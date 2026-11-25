/*
 * traceback_check.c
 *
 * End-to-end software proof of the hardware decode path WITHOUT Verilator:
 *
 *   dataset symbols --sw_acs--> survivor words --tracebackSurvivors--> decoded words
 *   compared against the shipped goldens.
 *
 * sw_acs() is an independent full-frame Hamming ACS in the RTL/accelerator
 * convention; it uses the REAL computeOutputTable() (now built with the
 * EEMBC-matching reversed generators 065/057) and the REAL tracebackSurvivors()
 * from ../viterb00.c -- the exact functions the hardware path uses. So a pass
 * here means: given correct survivor words, the decode matches the benchmark.
 *
 * The hardware is hard-decision Hamming, so gett/toggle are checked against the
 * *_golden_hamming.dat references (what a hard-decision decoder produces);
 * zeros/ones are metric-invariant and use the stock goldens.
 *
 * The only thing this does NOT cover is that the real RTL produces the same
 * survivor words sw_acs does -- that is leg B, confirmed on the VM by diffing
 * survivor_dump's rtl_survivors.txt against sw_acs for the same dataset.
 *
 * Build (from viterb00/test):
 *   cc -O2 -std=c99 -I stub -I .. traceback_check.c ../viterb00.c -o traceback_check
 *   ./traceback_check
 */
#include <stdio.h>
#include "algo.h"            /* MAX_DATA_SIZE, e_s16/e_u16, tracebackSurvivors() */

#define INF 0xFFFFu
#define NST 32

static n_int tsym(const unsigned int *t, n_int e) { n_int b = e * 2; return (t[b >> 5] >> (b & 31)) & 3; }
static n_int ham(n_int a, n_int b) { n_int x = a ^ b; return (x & 1) + ((x >> 1) & 1); }

/* Independent full-frame destination-centric Hamming ACS, RTL state numbering.
 * surv[c] bit d = chosen predecessor's low bit for destination d at column c. */
static void sw_acs(const e_s16 *in, unsigned int *surv)
{
    const unsigned int *t = computeOutputTable();   /* real table (065/057) */
    e_u16 acc[NST], nx[NST];
    n_int c, d;

    for (d = 0; d < NST; d++) acc[d] = (e_u16)((d == 0) ? 0 : INF);

    for (c = 0; c < MAX_DATA_SIZE; c++) {
        e_s16 ew  = in[c];
        n_int b0  = (((ew & 0x38) >> 3) < 4) ? 1 : 0;
        n_int b1  = ( (ew & 0x07)       < 4) ? 1 : 0;
        n_int recv = (b1 << 1) | b0;
        unsigned int w = 0;

        for (d = 0; d < NST; d++) {
            n_int input = (d >> 4) & 1;
            n_int pa = ((d & 0xf) << 1);
            n_int pb = pa | 1;
            n_int ea = tsym(t, (input << 5) | pa);
            n_int eb = tsym(t, (input << 5) | pb);
            unsigned ca = (acc[pa] == INF) ? 0x1FFFFu : (unsigned)acc[pa] + (unsigned)ham(ea, recv);
            unsigned cb = (acc[pb] == INF) ? 0x1FFFFu : (unsigned)acc[pb] + (unsigned)ham(eb, recv);
            n_int sv = (cb < ca) ? 1 : 0;                 /* ties -> predecessor A */
            unsigned ch = sv ? cb : ca;
            nx[d] = (e_u16)((ch >= INF) ? INF : ch);
            w |= (unsigned)sv << d;
        }
        for (d = 0; d < NST; d++) acc[d] = nx[d];
        surv[c] = w;
    }
}

static int cmp(const char *name, e_s16 *in, e_s16 *golden)
{
    static unsigned int surv[MAX_DATA_SIZE];
    e_s16 out[MAX_DATA_SIZE / 16 + 1];
    int n = MAX_DATA_SIZE / 16 + 1, i, bad = 0;

    sw_acs(in, surv);
    tracebackSurvivors(surv, MAX_DATA_SIZE, out);

    for (i = 0; i < n; i++)
        if ((out[i] & 0xffff) != (golden[i] & 0xffff)) {
            if (bad < 3)
                printf("     word %2d: got %04x  expected %04x\n",
                       i, (unsigned)(out[i] & 0xffff), (unsigned)(golden[i] & 0xffff));
            bad++;
        }

    printf("  %-14s %-5s  (", name, bad ? "FAIL" : "PASS");
    for (i = 0; i < n; i++) {
        int c1 = (out[i] >> 8) & 0xff, c2 = out[i] & 0xff;
        putchar(c1 >= 32 && c1 < 127 ? c1 : '.');
        putchar(c2 >= 32 && c2 < 127 ? c2 : '.');
    }
    printf(")\n");
    return bad ? 1 : 0;
}

int main(void)
{
    int fail = 0;

    { static e_s16 i[] = {
#include "datasets/zerosi.dat"
      }; static e_s16 g[] = {
#include "datasets/zeros_golden.dat"
      }; fail |= cmp("zeros", i, g); }

    { static e_s16 i[] = {
#include "datasets/onesi.dat"
      }; static e_s16 g[] = {
#include "datasets/ones_golden.dat"
      }; fail |= cmp("ones", i, g); }

    { static e_s16 i[] = {
#include "datasets/getti.dat"
      }; static e_s16 g[] = {
#include "datasets/gett_golden_hamming.dat"
      }; fail |= cmp("gett(hamming)", i, g); }

    { static e_s16 i[] = {
#include "datasets/togglei.dat"
      }; static e_s16 g[] = {
#include "datasets/toggle_golden_hamming.dat"
      }; fail |= cmp("toggle(hamming)", i, g); }

    printf("\n%s\n", fail ? "RESULT: mismatches (see above)"
                          : "RESULT: all datasets pass (sw_acs + tracebackSurvivors vs goldens)");
    return fail;
}
