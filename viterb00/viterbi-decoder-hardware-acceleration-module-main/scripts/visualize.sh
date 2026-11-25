#!/usr/bin/env sh
set -eu
cd "$(dirname "$0")/.."
mkdir -p build
iverilog -g2012 -Wall -s tb_viterbi -o build/visualize rtl/*.sv tb/tb_viterbi.sv
vvp build/visualize +TRACE=8 +WAVES
python3 scripts/render_trace.py
printf '\nOpen build/viterbi_trace.html in your browser. Waveforms: build/viterbi.vcd\n'
