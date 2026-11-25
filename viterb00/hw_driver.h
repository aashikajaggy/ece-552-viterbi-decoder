/*
 * hw_driver.h
 *
 * C-callable interface to the Verilator-compiled viterbi_accelerator model.
 *
 * The benchmark (C) calls these functions; hw_driver.cpp (C++) implements them
 * by driving the clock/handshake of the Verilated RTL model. One call to
 * hw_run_column() performs one ACS trellis stage.
 *
 * Usage sketch (benchmark side):
 *
 *     hw_init();                               // construct + reset the model, once
 *     hw_init_frame(seed_metrics, output_table);  // load_context: seed + table
 *     for (stage = 0; stage < NSTAGES; stage++)
 *         survivor_log[stage] = hw_run_column(symbol[stage]);
 *     hw_final();                              // tear down
 *
 * The 32 path metrics and the output table live INSIDE the model and persist
 * between columns. They are loaded ONCE per frame via load_context (hw_init_frame)
 * and are NOT resent each stage -- hw_run_column only presents the received
 * symbol and steps one ACS column.
 */
#ifndef HW_DRIVER_H
#define HW_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Construct the model and run the reset sequence. Call once before use. */
void hw_init(void);

/* Load a new frame via the RTL load_context strobe. Asserts load_context,
 * which (a) seeds the metric store and (b) latches the output table, then
 * sets 'configured' so columns can run. Call once per decoded frame, before
 * the first hw_run_column().
 *   seed_metrics : 32 starting path metrics, one per state (0..0xFFFF). For a
 *                  fresh frame use 0 at the encoder start state, INF (0xFFFF)
 *                  everywhere else -- the same initial column computeMetricTable
 *                  begins from. Packed here into initial_metrics[511:0].
 *   table        : 128-bit packed output table as 4 x 32-bit words
 *                  (exactly what computeOutputTable() returns). */
void hw_init_frame(const unsigned int seed_metrics[32], const unsigned int table[4]);

/* Run ONE ACS column (one trellis stage) via the start strobe. The output
 * table and the path metrics are already inside the model (loaded by
 * hw_init_frame / evolved by prior columns), so only the symbol is presented.
 *   received : 2-bit hard-decision received symbol (0..3)
 * Returns the 32-bit survivor word: bit s = the chosen predecessor's low bit
 * for destination state s this stage. Store it per stage for traceback. */
unsigned int hw_run_column(unsigned char received);

/* Non-zero if the metric store saturated (hit INF) on any column since the
 * last hw_init_frame(). Optional diagnostic. */
int hw_overflow(void);

/* Read back the current 32 path metrics (optional, for debug/verification).
 * out must point to space for 32 unsigned ints. */
void hw_read_metrics(unsigned int out[32]);

/* Run final blocks and free the model. Call once when done. */
void hw_final(void);

#ifdef __cplusplus
}
#endif

#endif /* HW_DRIVER_H */
