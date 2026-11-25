/*
 * hw_driver.cpp
 *
 * Adapter between the C benchmark and the Verilator-compiled
 * viterbi_accelerator RTL model. Implements the C-callable functions declared
 * in hw_driver.h by driving the model's clock and start/init/done handshake.
 *
 * This is the software equivalent of the SystemVerilog testbench tasks
 * (initialize_frame / step) in tb/tb_viterbi.sv.
 *
 * Build notes:
 *   1. Re-verilate the CURRENT RTL first (the shipped obj_dir is from an older
 *      port list). From the hardware module directory:
 *        verilator --cc --build \
 *          rtl/viterbi_accelerator.sv rtl/viterbi_controller.sv \
 *          rtl/viterbi_metric_store.sv rtl/viterbi_acs.sv rtl/hamming2.sv \
 *          --top-module viterbi_accelerator --Mdir obj_dir
 *   2. Compile this file as C++ with -I<obj_dir> -I<VERILATOR_ROOT>/include
 *   3. Link the benchmark objects + this + obj_dir/Vviterbi_accelerator__ALL.a
 *      + verilated.o using g++ (C++ runtime needed).
 *
 * Expected top-level ports (current RTL):
 *   in : clk, rst, load_context, initial_metrics[511:0], start,
 *        received[1:0], output_table[127:0]
 *   out: busy, done, configured, metrics[511:0], survivors[31:0],
 *        metric_overflow
 */

#include "Vviterbi_accelerator.h"
#include "verilated.h"

static Vviterbi_accelerator* dut = nullptr;

/* One full clock period with a single rising edge.
 * Verilator samples @(posedge clk) when clk transitions 0->1 during eval(). */
static inline void tick(void)
{
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}
// reset based
extern "C" void hw_init(void)
{
    if (dut) return;                 /* idempotent */
    dut = new Vviterbi_accelerator;

    /* Known state: all control low. */
    dut->clk = 0;
    dut->rst = 0;
    dut->load_context = 0;
    dut->start = 0;
    dut->received = 0;
    for (int i = 0; i < 16; i++) dut->initial_metrics[i] = 0;
    for (int i = 0; i < 4; i++)  dut->output_table[i]    = 0;

    /* Assert reset for a couple of clocks, then release. */
    dut->rst = 1;
    tick();
    tick();
    dut->rst = 0;
    dut->eval();
}

extern "C" void hw_init_frame(const unsigned int seed_metrics[32],
                              const unsigned int table[4])
{
    /* initialize = (!busy && load_context). With the module idle, pulsing
     * load_context for one clock loads BOTH the metric store (current[s] <-
     * initial_metrics) and the output table (table_q <- output_table), and
     * raises 'configured'. load_context has priority over start in the
     * controller, so a concurrent start is ignored this edge. */

    /* Pack 32 x 16-bit seed metrics into the 16 x 32-bit initial_metrics bus
     * (two metrics per word: low half = even state, high half = odd state). */
    // accumulation vector becomes 32 entries of 16 bits each
    for (int w = 0; w < 16; w++) {
        unsigned lo = seed_metrics[2 * w]     & 0xffffu;
        unsigned hi = seed_metrics[2 * w + 1] & 0xffffu;
        dut->initial_metrics[w] = (hi << 16) | lo;
    }
    // Verilator only stores 32-bit words
    for (int i = 0; i < 4; i++) dut->output_table[i] = table[i];

    dut->load_context = 1;
    dut->start = 0;
    tick();                          /* initialize edge: seed + table latched */
    dut->load_context = 0;
    dut->eval();                     /* 'configured' is now high */
    // now the verilog module is ready to start accepting requests
}

extern "C" unsigned int hw_run_column(unsigned char received)
{
    /* Present the symbol and strobe start. The table and metrics already live
     * in the model, so accept = (!busy && configured && !load_context && start)
     * latches 'received' and launches the ACS run. */
    dut->received = (CData)(received & 0x3);
    dut->start = 1;

    tick();                          /* accept edge: request latched, busy=1 */

    dut->start = 0;                  /* latched request is immune to this now */
    dut->eval();

    /* FSM: COMPUTE (group_index 0..7) then COMMIT asserts done (9 clocks).
     * Loop generically in case METRIC_WIDTH/group count ever changes. */
    int guard = 0;
    while (!dut->done) {
        tick();
        if (++guard > 1000) break;   /* safety: never hang the benchmark */
    }

    /* On the commit cycle, metrics/survivors are updated and done=1.
     * Read before clocking again (done is a 1-cycle pulse). */
    return (unsigned int)dut->survivors;
}

extern "C" int hw_overflow(void)
{
    return (int)dut->metric_overflow;
}

extern "C" void hw_read_metrics(unsigned int out[32])
{
    /* metrics is a 512-bit bus = 32 x 16-bit cells packed into 16 x 32-bit
     * Verilator words. Unpack two 16-bit metrics per word. */
    for (int s = 0; s < 32; s++) {
        unsigned int word = dut->metrics[s >> 1];
        out[s] = (s & 1) ? (word >> 16) & 0xffff : word & 0xffff;
    }
}

extern "C" void hw_final(void)
{
    if (!dut) return;
    dut->final();
    delete dut;
    dut = nullptr;
}
