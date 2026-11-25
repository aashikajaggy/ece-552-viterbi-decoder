/*
 * survivor_dump.c
 *
 * Drive the Verilator-compiled viterbi_accelerator RTL over a full
 * MAX_DATA_SIZE (344) column frame and write each column's 32-bit survivor
 * word to a text file, one word per line. The point is to produce the
 * HARDWARE survivor bits in a plain format you can diff against the
 * benchmark's survivor bits.
 *
 * This must be built with -DUSE_HW_ACCEL and linked against the Verilated
 * model + hw_driver.cpp (see build_survivors_vm.sh). It feeds the RTL the
 * exact same input symbols the EEMBC benchmark uses (the shipped datasets),
 * so the survivor words line up column-for-column with a benchmark run on
 * the same dataset.
 *
 * Dataset select (same macros the benchmark uses), default DATA_1 = gett:
 *   -DDATA_1  gett      -DDATA_2  toggle
 *   -DDATA_3  ones      -DDATA_4  zeros
 *
 * Usage:  ./survivor_dump [output_file]     (default: rtl_survivors.txt)
 */
#include <stdio.h>
#include "algo.h"          /* MAX_DATA_SIZE, e_s16, ... (stub thlib.h types) */

/* Implemented in ../viterb00.c under -DUSE_HW_ACCEL (drives the RTL) and in
 * ../hw_driver.cpp (frees the Verilated model). Declared here because they
 * are not in algo.h. */
void          computeACSLoop(e_s16 *EncodedStreamPtr);
unsigned int *getACSSurvivors(void);   /* MAX_DATA_SIZE survivor words */
void          hw_final(void);

/* The received soft-symbol stream, straight from the shipped dataset, exactly
 * as bmark.c builds its input_buf.  (-I .. makes "datasets/..." resolve to
 * ../datasets/..., same as selftest.c does.) */
#if defined(DATA_2)
static e_s16 input_buf[] = {
#  include "datasets/togglei.dat"
};
#  define DSNAME "toggle"
#elif defined(DATA_3)
static e_s16 input_buf[] = {
#  include "datasets/onesi.dat"
};
#  define DSNAME "ones"
#elif defined(DATA_4)
static e_s16 input_buf[] = {
#  include "datasets/zerosi.dat"
};
#  define DSNAME "zeros"
#else /* DATA_1 / default */
static e_s16 input_buf[] = {
#  include "datasets/getti.dat"
};
#  define DSNAME "gett"
#endif

int main(int argc, char **argv)
{
    const char  *outname = (argc > 1) ? argv[1] : "rtl_survivors.txt";
    unsigned int *sv;
    FILE        *f;
    int          c;

    /* Run the whole frame on the hardware. computeACSLoop() constructs and
     * resets the model (hw_init), loads the metric seed + output table
     * (hw_init_frame / load_context), then runs one ACS column per symbol,
     * storing each 32-bit survivor word in g_acs_survivors[]. */
    computeACSLoop(input_buf);
    sv = getACSSurvivors();

    f = fopen(outname, "w");
    if (!f) { perror(outname); return 2; }

    fprintf(f, "# viterbi_accelerator RTL survivor words\n");
    fprintf(f, "# dataset = %s, columns = %d\n", DSNAME, MAX_DATA_SIZE);
    fprintf(f, "# each line: <column> <survivor_word_hex>  (bit s = decision for state s)\n");
    for (c = 0; c < MAX_DATA_SIZE; c++)
        fprintf(f, "%3d %08x\n", c, sv[c]);

    fclose(f);
    hw_final();

    printf("survivor_dump: wrote %d RTL survivor words (dataset %s) to %s\n",
           MAX_DATA_SIZE, DSNAME, outname);
    return 0;
}
