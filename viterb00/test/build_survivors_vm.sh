#!/usr/bin/env bash
#
# build_survivors_vm.sh
#
# Build and run survivor_dump on a machine that has Verilator installed
# (e.g. your VM). It verilates the viterbi_accelerator RTL, links it with the
# C benchmark sources + the C++ driver shim, runs the whole 344-column frame on
# the hardware model, and writes the RTL's per-column survivor words to a file
# you can diff against the benchmark's survivor bits.
#
# Usage (run on the VM, from this test/ directory or anywhere):
#   ./build_survivors_vm.sh [DATA] [OUTFILE]
#     DATA     dataset: 1=gett (default)  2=toggle  3=ones  4=zeros
#     OUTFILE  output file (default: <test>/rtl_survivors.txt)
#
# Requires: verilator on PATH, a C compiler (cc), and g++.
#
set -euo pipefail

# --- resolve paths relative to this script ----------------------------------
TESTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRCDIR="$(cd "$TESTDIR/.." && pwd)"                 # viterb00/
RTLDIR="$SRCDIR/viterbi-decoder-hardware-acceleration-module-main/rtl"
OBJDIR="$TESTDIR/obj_dir"                            # fresh, isolated model build
BUILD="$TESTDIR/build"

DATA="${1:-1}"
OUT="${2:-$TESTDIR/rtl_survivors.txt}"

# --- find verilator + its runtime library -----------------------------------
if ! command -v verilator >/dev/null 2>&1; then
    echo "ERROR: 'verilator' not on PATH. Run this on the VM where Verilator is" >&2
    echo "       installed (or 'brew install verilator' / add it to PATH)."      >&2
    exit 1
fi
VROOT="$(verilator --getenv VERILATOR_ROOT)"
VINC="$VROOT/include"
if [ ! -f "$VINC/verilated.cpp" ]; then
    echo "ERROR: Verilator runtime not found at $VINC/verilated.cpp" >&2
    exit 1
fi
echo "verilator      : $(command -v verilator)  ($(verilator --version))"
echo "VERILATOR_ROOT : $VROOT"

CC="${CC:-cc}"
CXX="${CXX:-g++}"
CXXSTD="-std=c++17"
# C include dirs: stub thlib.h/eembc_dt.h, plus viterb00/ for algo.h/hw_driver.h
# and so "datasets/<set>.dat" resolves to viterb00/datasets/<set>.dat.
mkdir -p "$BUILD"

# --- 1. verilate the RTL into a fresh model ---------------------------------
echo "== [1/5] verilating RTL -> $OBJDIR =="
verilator --cc --build \
    "$RTLDIR/viterbi_accelerator.sv" "$RTLDIR/viterbi_controller.sv" \
    "$RTLDIR/viterbi_metric_store.sv" "$RTLDIR/viterbi_acs.sv" \
    "$RTLDIR/hamming2.sv" \
    --top-module viterbi_accelerator --Mdir "$OBJDIR"

# --- 2. compile the C benchmark sources (no EEMBC harness, stub headers) -----
echo "== [2/5] compiling C sources (-DUSE_HW_ACCEL, -DDATA_$DATA) =="
$CC -O2 -std=c99 -DUSE_HW_ACCEL -I "$TESTDIR/stub" -I "$SRCDIR" \
    -c "$SRCDIR/viterb00.c" -o "$BUILD/viterb00.o"
$CC -O2 -std=c99 -DUSE_HW_ACCEL -DDATA_$DATA -I "$TESTDIR/stub" -I "$SRCDIR" \
    -c "$TESTDIR/survivor_dump.c" -o "$BUILD/survivor_dump.o"

# --- 3. compile the C++ driver shim (talks to the Verilated model) ----------
echo "== [3/5] compiling hw_driver.cpp =="
$CXX -O2 $CXXSTD -I "$OBJDIR" -I "$VINC" -c "$SRCDIR/hw_driver.cpp" -o "$BUILD/hw_driver.o"

# --- 4. collect the Verilator runtime objects -------------------------------
# verilated.cpp references VlThreadPool (in verilated_threads.cpp), so BOTH are
# required. 'verilator --build' already compiled them into obj_dir with the
# right flags -- prefer those (ABI-consistent); fall back to compiling from the
# include dir if absent.
echo "== [4/5] collecting Verilator runtime =="
RT_OBJS=()
for f in verilated verilated_threads; do
    if [ -f "$OBJDIR/$f.o" ]; then
        RT_OBJS+=("$OBJDIR/$f.o")
    elif [ -f "$VINC/$f.cpp" ]; then
        $CXX -O2 $CXXSTD -I "$VINC" -I "$VINC/vltstd" -c "$VINC/$f.cpp" -o "$BUILD/$f.o"
        RT_OBJS+=("$BUILD/$f.o")
    fi
done

# the Verilated model library (archive, or the __ALL.o if no archive was made)
MODEL="$OBJDIR/Vviterbi_accelerator__ALL.a"
[ -f "$MODEL" ] || MODEL="$OBJDIR/Vviterbi_accelerator__ALL.o"

# --- 5. link (C++ linker + -pthread: the runtime uses std::thread) ----------
echo "== [5/5] linking survivor_dump =="
$CXX -O2 $CXXSTD -pthread -o "$BUILD/survivor_dump" \
    "$BUILD/survivor_dump.o" "$BUILD/viterb00.o" "$BUILD/hw_driver.o" \
    "${RT_OBJS[@]}" "$MODEL"

echo "== running =="
"$BUILD/survivor_dump" "$OUT"
echo
echo "Done. RTL survivor words (dataset DATA_$DATA) are in:"
echo "    $OUT"
echo "Each line is '<column> <32-bit hex>', bit s = the ACS decision for state s."
