# Current validation — software metric-column handoff (2026-11-09)

Ran `sh scripts/test.sh` with Icarus Verilog after changing the context interface:

```
PASS ACS: 4096 exhaustive cases
PASS accelerator W=16: 269 columns, all metrics/survivors and timing
PASS accelerator W=3: 269 columns, all metrics/survivors and timing
```

The W=16 test computes five warm-up columns in the independent forward-edge
reference, loads the fifth column plus output table, and checks hardware
continuation for 128 symbols. The W=3 run starts from a software-supplied seed
column instead, to isolate deliberate finite-width saturation testing.
Both widths also check 100 arbitrary imported columns/tables, ties, unreachable
paths, overflow, load-over-start priority, ignored starts before configuration,
persistent tables despite input changes, ignored busy loads/starts, atomic
publication, reset abort, reconfiguration, and nine-period completion latency.
Each completed column is checked for all 32 metrics and all 32 survivor bits.
Compilation produced no warnings. The ACS arithmetic is unchanged.

These are simulation-based checks, not formal equivalence. No processor wrapper,
actual RISC-V program, end-to-end traceback, gem5 integration, Vivado synthesis,
placement/routing, or physical timing/power measurement was performed.

---

## Historical validation (prior interface)

# Original validation

Executed with Icarus Verilog 12.0 on 2026-11-02 using `sh scripts/test.sh`.

```
PASS ACS: 4096 exhaustive cases
PASS accelerator W=16: 269 columns, all metrics/survivors and timing
PASS accelerator W=3: 269 columns, all metrics/survivors and timing
```

The accelerator scoreboard independently enumerates forward trellis transitions,
while the RTL computes pairs of incoming predecessors. All 32 metrics and all 32
survivor bits are compared after every completed column. Narrow metrics exercise
saturation and sticky overflow. The test also checks eight compute cycles plus
one commit cycle, atomic publication, latched inputs, ignored busy commands,
initialization priority, nonzero initial state, synchronous reset during computation,
and the one-cycle done pulse. ACS inputs exhaust all 3-bit metrics and all 2-bit
symbols, including ties, infinity and finite overflow.

RTL compilation and behavioral simulation passed without compiler warnings.
Vivado synthesis/implementation and Verilator execution were not run because
those tools are not available in this environment. Their commands are supplied
for local use. No FPGA frequency, resource, power, BER, MATLAB agreement or CPU
speedup is claimed. The testbench validates metric updates; external traceback
and processor integration still require their own verification.

## Visualization update — 2026-11-03

Original regression rerun successfully: 4,096 ACS cases and 269 columns at each
of widths 16 and 3. Trace-enabled width-16 run also passed all 269 columns.
The report generator checked 256 observed ACS results against 256 published
metrics and survivor decisions across the first eight requests. CSV, VCD and
self-contained HTML outputs were generated successfully. No RTL changed.
