# Validation

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
