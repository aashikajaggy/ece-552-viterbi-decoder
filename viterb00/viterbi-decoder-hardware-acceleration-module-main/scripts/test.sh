#!/usr/bin/env sh
set -eu
cd "$(dirname "$0")/.."
mkdir -p build
iverilog -g2012 -Wall -s tb_acs -o build/acs rtl/*.sv tb/tb_acs.sv
vvp build/acs
for width in 16 3; do
    iverilog -g2012 -Wall -s tb_viterbi -Ptb_viterbi.W=$width -o build/viterbi_$width rtl/*.sv tb/tb_viterbi.sv
    vvp build/viterbi_$width
done
