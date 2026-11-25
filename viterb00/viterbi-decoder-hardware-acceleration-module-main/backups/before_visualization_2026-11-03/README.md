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
| `init`, `initial_state[4:0]` | While idle, initialize that state's metric to 0 and all others to infinity |
| `start` | Accepted on an idle edge if `init` is low; pulse for one cycle |
| `received[1:0]` | One hard-decision received symbol, latched on acceptance |
| `output_table[127:0]` | All 64 expected symbols, latched on acceptance |
| `busy` | High from acceptance through computation, low after commit |
| `done` | One-cycle pulse following commit; results are valid and stable |
| `metrics[32*METRIC_WIDTH-1:0]` | State s is `metrics[s*METRIC_WIDTH +: METRIC_WIDTH]` |
| `survivors[31:0]` | Bit s selects predecessor for destination s, as defined below |
| `metric_overflow` | Sticky saturation indication, cleared by reset or accepted init |

Reset initializes state 0. Priority is reset, then idle initialization, then idle
start. `init` and `start` while busy are ignored, not queued. An asserted `start`
held until the next idle edge will be accepted again. Deassert it after acceptance.
The table and received-symbol inputs may change while busy. Initialization can be
followed by a start on the very next edge. Initialize again before each new frame.

If request acceptance is edge E0, groups 0–7 compute at E1–E8. Commit at E9
publishes all 32 metrics and survivors atomically and asserts done. The next
request can be accepted at E10: **9 clock periods acceptance-to-done, 10 clock
periods minimum between accepted requests**, including the input-load edge.
The eight compute cycles are not an eight-cycle end-to-end CPU instruction.
Results remain stable until initialization, reset or the next commit. No output
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
There is no normalization. From a zero initial metric, a sufficient safe frame
bound is `2*N < 2**METRIC_WIDTH - 1`. At width 16, N<=32767 symbols is safe;
at width 8, N<=127 is safe. These conservative bounds include termination symbols.
Increase the width for longer frames or add a separately verified normalization
scheme. Initialization discards all prior path history.

## Run simulations

From the extracted folder with Icarus Verilog on PATH:

```sh
sh scripts/test.sh
```

The tests compare every state and survivor for example-code and arbitrary tables,
exercise changing busy inputs, ignored busy commands, initialization priority,
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
eight-cycle metric-column computation at K=6. Its evaluated accelerator uses
soft-decision distances and processor-specific integration. This implementation
uses the requested hard-decision Hamming distances and a newly documented generic
interface. It does not reproduce the paper's opcodes, data buses, sub-state mode,
software overheads, physical measurements or processor speedup claims. The
proposal provides the project context; the current request defines this deliverable.
