# Tests for the Viterbi decoder. Run from the viterb00/ directory as
#   make -C test <target>   (or from here as  make <target>).
#
# Targets:
#   check   fast correctness check  (selftest, no EEMBC harness needed)
#   bench   real EEMBC bmark_lite    (full th_lite harness: timing + CRC)
#   clean   remove built binaries
#
# "check" builds selftest against ../viterb00.c using the stub thlib.h in
# ./stub. "bench" builds the actual benchmark the EEMBC makefiles build,
# just invoked directly instead of through their multi-toolchain layers.

CC      ?= cc
SRCDIR   = ..
ROOT     = ../../..
THLITE   = $(ROOT)/th_lite

# --- fast correctness check (no harness) ------------------------------------
CFLAGS   = -O2 -I stub -I $(SRCDIR)

selftest: selftest.c $(SRCDIR)/viterb00.c $(SRCDIR)/algo.h
	$(CC) $(CFLAGS) -o $@ selftest.c $(SRCDIR)/viterb00.c

.PHONY: check
check: selftest
	./selftest

# --- real EEMBC benchmark (timing + CRC, via th_lite harness) ---------------
# Change the dataset with DATA=1..4 (1 gett, 2 toggle, 3 ones, 4 zeros=default)
# and add the CRC check with CRC=1, e.g.:  make -C test bench DATA=1 CRC=1
DATA     ?=
CRC      ?=
BENCHDEF = $(if $(DATA),-DDATA_$(DATA)) $(if $(CRC),-DNON_INTRUSIVE_CRC_CHECK)
BENCHINC = -I $(SRCDIR) -I $(SRCDIR)/datasets -I $(SRCDIR)/.. \
           -I $(ROOT)/telecom \
           -I $(THLITE)/x86/al -I $(THLITE)/src
BENCHSRC = $(SRCDIR)/bmark_lite.c $(SRCDIR)/viterb00.c \
           $(THLITE)/src/thlib.c $(THLITE)/src/crc.c $(THLITE)/src/heap.c \
           $(THLITE)/x86/al/thal.c

viterbi_bench: $(SRCDIR)/bmark_lite.c $(SRCDIR)/viterb00.c
	$(CC) -O2 $(BENCHDEF) $(BENCHINC) -o $@ $(BENCHSRC)

.PHONY: bench
bench: viterbi_bench
	./viterbi_bench

# Build + run the real benchmark for every dataset, with the CRC check on.
.PHONY: benchall
benchall:
	@for d in 1 2 3 4; do \
	  name=`echo "gett toggle ones zeros" | cut -d' ' -f$$d`; \
	  echo "===== DATA_$$d ($$name) ====="; \
	  $(CC) -O2 -DDATA_$$d -DNON_INTRUSIVE_CRC_CHECK $(BENCHINC) -o viterbi_bench $(BENCHSRC) 2>/dev/null; \
	  ./viterbi_bench | grep -E "Non-Intrusive CRC|Iterations/Sec|DONE|Failure"; \
	  echo ""; \
	done

.PHONY: clean
clean:
	rm -f selftest viterbi_bench
