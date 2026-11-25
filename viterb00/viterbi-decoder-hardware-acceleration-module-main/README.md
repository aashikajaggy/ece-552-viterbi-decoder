# K=6 hard-decision Viterbi metric accelerator

Synthesizable SystemVerilog for 32 states, rate 1/2, four parallel ACS units
(each with two 2-bit Hamming-distance units), and eight compute cycles per symbol.
This is a branch/path metric engine. Save the 32 survivor bits after each `done`
for external traceback; no decoded-bit stream, traceback RAM, CPU wrapper,
instruction encoding, AXI interface or gem5 integration is supplied.

## Files

| File | Purpose |
|---|---|
| `rtl/hamming2.sv` | Two-bit Hamming distance, values 0–2 |
| `rtl/viterbi_acs.sv` | Extended add/compare/select, ties, infinity and saturation |
| `rtl/viterbi_controller.sv` | IDLE / eight COMPUTE cycles / COMMIT |
| `rtl/viterbi_metric_store.sv` | Current and pending 32-entry register banks |
| `rtl/viterbi_accelerator.sv` | Top level, input latches, four ACS instances |
| `tb/tb_acs.sv` | Exhaustive small-width ACS test |
| `tb/tb_viterbi.sv` | Independent forward-edge reference model and protocol tests |
| `scripts/test.sh` | Run Icarus tests |
| `scripts/synth.tcl` | Vivado out-of-context synthesis and reports |
| `VALIDATION.md` | Checks performed on this delivery |

## Interface and timing

All inputs are synchronous to rising `clk`. `rst` is active-high synchronous reset
and aborts an in-flight operation. Parameter `METRIC_WIDTH` defaults to 16 and must
be at least 2. Ports use packed vectors for simulator/tool portability.

| Port | Meaning |
|---|---|
| `load_context` | While idle, atomically load both the software metric column and output table; takes priority over start |
| `initial_metrics[32*METRIC_WIDTH-1:0]` | Software-computed K-1th metric column; state s occupies `[s*METRIC_WIDTH +: METRIC_WIDTH]` |
| `output_table[127:0]` | All 64 expected symbols; captured only on accepted `load_context` |
| `start` | Accepted while idle and configured, with `load_context` low; pulse for one cycle |
| `received[1:0]` | One hard-decision received symbol, latched on accepted start |
| `configured` | A context has been loaded since reset; does not mean idle or result-valid |
| `busy` | High from acceptance through computation, low after commit |
| `done` | One-cycle pulse following commit; results are valid and stable |
| `metrics[32*METRIC_WIDTH-1:0]` | State s is `metrics[s*METRIC_WIDTH +: METRIC_WIDTH]` |
| `survivors[31:0]` | Bit s selects predecessor for destination s, as defined below |
| `metric_overflow` | Sticky saturation indication, cleared by reset or accepted context load |

The former `init` and `initial_state` inputs have been removed. Reset clears
`configured`, sets every metric to infinity, and clears survivors and overflow.
It does not choose a starting encoder state. Starts before configuration are ignored.
Priority is reset, then idle context load, then configured idle start.
`load_context` and `start` while busy are ignored, not queued. Held requests can
be accepted on a later idle edge; deassert each after its intended acceptance.
A context load does not assert `done`; `configured` is set on the loading edge.
A start may be accepted on the next edge after loading.

Software computes the output table and first five metric columns (K-1=5),
then presents the fifth column and table and pulses `load_context`. The first
hardware request is for the sixth symbol. Subsequent starts reuse the local
output table and preceding hardware result, without reloading either input.
Reload context before a new frame. Loading clears old pending results, survivors,
and the hardware overflow flag. Software must reject an already-overflowed input
column; the core cannot distinguish saturated software values from unreachable states.

The packed ports connect to processor-side staging registers, not directly to a
single scalar CPU register. At W=16 the column is 512 bits: 16 RV32 words (or 8
RV64 words). The table is 128 bits: 4 RV32 words (or 2 RV64 words). A future custom
instruction or MMIO wrapper must assemble these words, drive both packed inputs,
and issue the atomic load. For RV32/W=16, staging word i contains metric 2*i in
bits [15:0] and metric 2*i+1 in bits [31:16]; table word i is bits [32*i +: 32].
No register-file access, bus transactions, or wrapper is implemented by this core.
The context-load edge is not the complete CPU transfer latency.

Software must save history for the first five steps and each hardware step, then
perform traceback. It may save metric columns as in the paper or use the compact
survivor-word approach (including software-generated warm-up survivor words).
The new load imports metrics only; it does not reconstruct earlier history.

If request acceptance is edge E0, groups 0–7 compute at E1–E8. Commit at E9
publishes all 32 metrics and survivors atomically and asserts done. The next
request can be accepted at E10: **9 clock periods acceptance-to-done, 10 clock
periods minimum between accepted requests**, including the input-load edge.
The eight compute cycles are not an eight-cycle end-to-end CPU instruction.
Results remain stable until context load, reset or the next commit. No output
backpressure is provided; capture survivors before the next result replaces them.

## Trellis and output-table convention

This package fixes an explicit convention; adapt MATLAB/software tables to it.
State is the previous five input bits, newest at bit 4. With input bit u:

```
destination = (predecessor >> 1) | (u << 4)
entry       = 32*u + predecessor
expected    = output_table[2*entry +: 2]
```

The least significant 64 table bits contain input-0 transitions in state order,
the upper 64 bits contain input-1 transitions. Symbol bits must use the same
ordering as `received`. For destination s, u=s[4], predecessor A=(s&15)<<1,
and predecessor B=A|1. Survivor 0 selects A; survivor 1 selects B. Equal costs
select A, including two unreachable paths. During reverse traceback the decoded
input is s[4] and the previous state is `{s[3:0], survivors_for_that_step[s]}`.
Only trace from a reachable final state (known termination state or minimum
metric state); survivors for unreachable states are placeholders.

No generator polynomial is hard-coded in the RTL. The testbench's octal 53/75
masks on `{u,state}` are example test data, not claimed project or paper parameters.
For MATLAB trellis exports, verify the state numbering, nextStates mapping, and
output-bit ordering against the equations above before packing the table.

## Metric range

All-ones is reserved for infinity. Infinity stays infinity; finite additions use
one extra bit and saturate to infinity instead of wrapping. `metric_overflow`
indicates that at least one selected finite result reached the reserved value;
results after this indication must not be treated as an exact Viterbi calculation.
The flag may assert during compute; inspect it together with `done`.
There is no normalization. If M is the largest finite loaded metric, a sufficient
bound for N additional symbols is `M + 2*N < 2**METRIC_WIDTH - 1`.
For a full frame beginning with a zero path metric in software, the conservative
bound `2*N_total < 2**METRIC_WIDTH - 1` includes software warm-up and termination.
At width 16, N_total<=32767 is safe. Increase the width for longer frames or add a
separately verified normalization scheme.

## Run simulations

From the extracted folder with Icarus Verilog on PATH:

```sh
sh scripts/test.sh
```

The tests compare every state and survivor for example-code and arbitrary tables,
exercise the five-symbol software handoff (W=16), packed column loads, persistent
output tables, starts before configuration, changing busy inputs, ignored busy
commands, context-load priority,
reset abort, result stability, exact latency, ties, unreachable paths and overflow.
The narrow-width run deliberately saturates. A fatal assertion gives a nonzero exit.

With a recent Verilator that supports timed SystemVerilog testbenches:

```sh
verilator --binary --timing -Wno-fatal --top-module tb_viterbi --Mdir build/obj_dir rtl/*.sv tb/tb_viterbi.sv
./build/obj_dir/Vtb_viterbi
```

Use `-GW=3` for the saturation run; use `--top-module tb_acs` with `tb/tb_acs.sv`
for the ACS test. `-Wno-fatal` permits lint warnings; review them for your tool
version. These tests validate metric computation, not BER or a full decoder.

## Vivado

Add only `rtl/*.sv` as design sources, select `viterbi_accelerator` as synthesis
top, and add the testbenches as simulation-only sources. Select `tb_viterbi` for
simulation. Run behavioral simulation for at least 100 us or until `$finish`.
For batch synthesis, replace the part name and clock period with your own:

```sh
vivado -mode batch -source scripts/synth.tcl -tclargs YOUR_FPGA_PART 10.0
```

This creates synthesis utilization/timing reports under `build/`. The period is
in ns and is a target, not a measured maximum frequency. The design uses registers
and multiplexers for multiport metric access; it does not assume BRAM inference.
The wide external table and metric ports are integration signals, not a proposed
physical pinout. Set system I/O delays/constraints and run placement/routing in
an actual integration before claiming timing, area or power results.

## Architectural sources and scope

Context: supplied `Viterbi_Accelerator.pdf`, Azhar et al., “Viterbi accelerator
for embedded processor datapaths,” ASAP 2012, sections III-C and Fig. 8; and the
supplied graded proposal, “A Lightweight Viterbi Decoding Extension for Embedded
RISC-V Processors,” by Lindenbaum, Kaarls and Jagadeesh, pp. 1–2.
The paper motivates local previous-column storage, four compute units and an
eight-cycle metric-column computation at K=6. The context-load interface now
supports the software warm-up and metric-column handoff in Fig. 8. Its evaluated accelerator uses
soft-decision distances and processor-specific integration. This implementation
uses the requested hard-decision Hamming distances and a newly documented generic
interface. It does not reproduce the paper's opcodes, data buses, sub-state mode,
software overheads, physical measurements or processor speedup claims. The
proposal provides the project context; the current request defines this deliverable.


## Visualize metric-table updates (added November 3, 2026)

From this folder run:

```sh
sh scripts/visualize.sh
```

Requires Icarus Verilog (`iverilog` and `vvp`) and Python 3. It runs the existing
16-bit self-checking testbench, records the first eight requests, and generates:

- `build/viterbi_trace.html`: self-contained interactive report; double-click to
  open in a browser. Select a request and use Next/Back or the cycle slider.
- `build/acs_trace.csv`: four actual ACS results per compute edge, with
  predecessor metrics, expected symbols, Hamming distances and survivor choices.
- `build/commits.csv`: all 32 published metrics and survivors after each commit.
- `build/viterbi.vcd`: waveforms for the complete 16-bit test run. Open in a VCD
  viewer if desired; no waveform viewer is needed for the HTML report.

On macOS, after the script finishes:

```sh
open build/viterbi_trace.html
```

The browser report shows the controller sequence, four branch comparisons, the
old/current and pending metric tables, survivor decisions, and the 64-entry
expected-output lookup table. Metrics update; the expected-output table remains
latched until the next context load. These are not FPGA LUT utilization measurements.
At E1–E8 each selected group has just been written to pending storage. At E9 the
new column is published. A dash means no new value for this request yet, not a
claim that the underlying register has been cleared. Candidate sums are displayed
before saturation, and INF denotes the reserved all-ones metric.

To record a different number of requests, after compiling with visualize.sh:

```sh
vvp build/visualize +TRACE=16 +WAVES
python3 scripts/render_trace.py
```

Changing TRACE overwrites the CSV files. WAVES overwrites the VCD. Omit WAVES if
only the browser report is needed. Request numbering starts at 1 and continues
across context loads/reset; it is a transaction count, not a frame index.
The example polynomial inputs are test data, not your MATLAB data.

`sh scripts/test.sh` runs the current regression without tracing. The first traced
request now follows five software-computed columns; it processes symbol six. The trace generator verifies that the observed
ACS results match the committed output column; the testbench independently
checks every metric and survivor against its reference algorithm.
