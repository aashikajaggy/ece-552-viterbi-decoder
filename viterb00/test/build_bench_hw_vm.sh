#!/usr/bin/env bash
#
# build_bench_hw_vm.sh
#
# Build and run the REAL EEMBC th_lite benchmark harness (bmark_lite.c) driving
# the Verilator viterbi_accelerator RTL instead of the software decoder. This is
# the actual EEMBC test harness (timing + golden check + CRC-vs-EXPECTED_CRC),
# with the decode loop calling computeACSLoop()+tracebackACSSurvivors() under
# -DUSE_HW_ACCEL. gett/toggle are already wired to the *_golden_hamming.dat
# references inside bmark_lite.c.
#
# Run on the VM (where Verilator is installed), from this test/ directory:
#   ./build_bench_hw_vm.sh [DATA]
#     DATA  dataset: 1=gett (default)  2=toggle  3=ones  4=zeros
#
# Requires: verilator on PATH, cc, g++, and the th_lite + telecom trees present
# (see the "FILES NEEDED ON THE VM" note at the bottom of this script).
#
set -euo pipefail

TESTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRCDIR="$(cd "$TESTDIR/.." && pwd)"                       # viterb00/
ROOT="$(cd "$TESTDIR/../../.." && pwd)"                   # telebench-git/
THLITE="$ROOT/th_lite"
TELECOM="$ROOT/telecom"
RTLDIR="$SRCDIR/viterbi-decoder-hardware-acceleration-module-main/rtl"
OBJDIR="$TESTDIR/obj_dir"
BUILD="$TESTDIR/build"
DATA="${1:-1}"

# the computer environment must have Verilator set up as part of the path
for d in "$THLITE/src" "$THLITE/x86/al" "$TELECOM"; do
    [ -d "$d" ] || { echo "ERROR: missing harness tree: $d" >&2;
                     echo "       (see FILES NEEDED ON THE VM at the end of this script)" >&2; exit 1; }
done
command -v verilator >/dev/null 2>&1 || { echo "ERROR: verilator not on PATH" >&2; exit 1; }
VROOT="$(verilator --getenv VERILATOR_ROOT)"; VINC="$VROOT/include"
CC="${CC:-cc}"; CXX="${CXX:-g++}"; CXXSTD="-std=c++17"
mkdir -p "$BUILD"

# EEMBC harness include dirs (mirrors test/makefile 'bench' target) + hamming CRC check
INC=(-I "$SRCDIR" -I "$SRCDIR/datasets" -I "$SRCDIR/.." -I "$TELECOM" -I "$THLITE/x86/al" -I "$THLITE/src")
DEF=(-DUSE_HW_ACCEL -DDATA_$DATA -DNON_INTRUSIVE_CRC_CHECK)

echo "verilator      : $(verilator --version)"
echo "th_lite        : $THLITE"
echo "telecom        : $TELECOM"

# --- 1. verilate the RTL ----------------------------------------------------
# Only (re)verilate if the compiled model is missing. Delete "$OBJDIR" (or run
# a clean) to force regeneration after editing the .sv sources.
if [ -f "$OBJDIR/Vviterbi_accelerator__ALL.a" ] || [ -f "$OBJDIR/Vviterbi_accelerator__ALL.o" ]; then
    echo "== [1/4] RTL already verilated ($OBJDIR) -- skipping; rm -rf it to force a rebuild =="
else
    echo "== [1/4] verilating RTL =="
    verilator --cc --build \
        "$RTLDIR/viterbi_accelerator.sv" "$RTLDIR/viterbi_controller.sv" \
        "$RTLDIR/viterbi_metric_store.sv" "$RTLDIR/viterbi_acs.sv" "$RTLDIR/hamming2.sv" \
        --top-module viterbi_accelerator --Mdir "$OBJDIR"
fi

# --- 2. compile C: benchmark + decoder + th_lite harness --------------------
echo "== [2/4] compiling C (benchmark + th_lite harness, -DUSE_HW_ACCEL -DDATA_$DATA) =="
$CC -O2 "${DEF[@]}" "${INC[@]}" -c "$SRCDIR/bmark_lite.c"  -o "$BUILD/bmark_lite.o"
$CC -O2 -DUSE_HW_ACCEL "${INC[@]}" -c "$SRCDIR/viterb00.c" -o "$BUILD/viterb00.o"
$CC -O2 "${INC[@]}" -c "$THLITE/src/thlib.c"    -o "$BUILD/thlib.o"
$CC -O2 "${INC[@]}" -c "$THLITE/src/crc.c"      -o "$BUILD/crc.o"
$CC -O2 "${INC[@]}" -c "$THLITE/src/heap.c"     -o "$BUILD/heap.o"
$CC -O2 "${INC[@]}" -c "$THLITE/x86/al/thal.c"  -o "$BUILD/thal.o"

# --- 3. compile C++ driver shim + collect Verilator runtime -----------------
echo "== [3/4] compiling hw_driver.cpp + collecting Verilator runtime =="
$CXX -O2 $CXXSTD -I "$OBJDIR" -I "$VINC" -c "$SRCDIR/hw_driver.cpp" -o "$BUILD/hw_driver.o"
RT_OBJS=()
for f in verilated verilated_threads; do
    if   [ -f "$OBJDIR/$f.o" ]; then RT_OBJS+=("$OBJDIR/$f.o")
    elif [ -f "$VINC/$f.cpp" ]; then
        $CXX -O2 $CXXSTD -I "$VINC" -I "$VINC/vltstd" -c "$VINC/$f.cpp" -o "$BUILD/$f.o"
        RT_OBJS+=("$BUILD/$f.o")
    fi
done
MODEL="$OBJDIR/Vviterbi_accelerator__ALL.a"
[ -f "$MODEL" ] || MODEL="$OBJDIR/Vviterbi_accelerator__ALL.o"

# --- 4. link (g++ + -pthread) and run ---------------------------------------
# bmark_lite.c is the main entry point for the tests
echo "== [4/4] linking viterbi_bench_hw =="
$CXX -O2 $CXXSTD -pthread -o "$BUILD/viterbi_bench_hw" \
    "$BUILD/bmark_lite.o" "$BUILD/viterb00.o" \
    "$BUILD/thlib.o" "$BUILD/crc.o" "$BUILD/heap.o" "$BUILD/thal.o" \
    "$BUILD/hw_driver.o" "${RT_OBJS[@]}" "$MODEL"

# single executable with all of the files 
echo "== running EEMBC harness over the RTL (DATA_$DATA) =="
"$BUILD/viterbi_bench_hw"

# ----------------------------------------------------------------------------
# FILES NEEDED ON THE VM (relative to the telebench-git root):
#   ece-552-viterbi-decoder/viterb00/            viterb00.c algo.h hw_driver.{c,h}pp
#                                                bmark_lite.c datasets/ test/
#   ece-552-viterbi-decoder/viterb00/viterbi-decoder-hardware-acceleration-module-main/rtl/*.sv
#   th_lite/src/      thlib.c crc.c heap.c  + *.h (heap.h thal.h thassert.h therror.h
#                                                   thlib.h thvinfo.h)
#   th_lite/x86/al/   thal.c  + eembc_dt.h heapport.h thcfg.h
#   telecom/          harness.h
# Plus Verilator installed on PATH. (th_lite and telecom live OUTSIDE the
# ece-552-viterbi-decoder git repo, so they are NOT transferred by cloning it.)
# ----------------------------------------------------------------------------
