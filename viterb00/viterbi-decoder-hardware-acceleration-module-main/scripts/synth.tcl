# Usage from package root: vivado -mode batch -source scripts/synth.tcl -tclargs PART PERIOD_NS
if {$argc != 2} { error "Supply target FPGA PART and clock PERIOD_NS" }
set part [lindex $argv 0]
set period [lindex $argv 1]
file mkdir build
read_verilog -sv [glob rtl/*.sv]
synth_design -top viterbi_accelerator -part $part -mode out_of_context
create_clock -name clk -period $period [get_ports clk]
report_utilization -file build/utilization.rpt
report_timing_summary -file build/timing_synth.rpt
write_checkpoint -force build/viterbi_synth.dcp
# These are synthesis estimates. Add board/integration constraints and implement
# the complete system for signoff timing, resource and power measurements.
