/*
 * legb_check.c
 *
 * Close "leg B" of the hardware validation using the RTL survivor dumps
 * produced on the VM (rtl_<set>.txt from survivor_dump / build_survivors_vm.sh):
 *
 *   1) sw_acs survivors   vs   RTL survivors        (do the RTL ACS decisions
 *                                                    match the software model?)
 *   2) tracebackSurvivors(RTL survivors)  vs  golden (does the RTL decode, run
 *                                                    through the real traceback,
 *                                                    match the benchmark?)
 *
 * Uses the REAL computeOutputTable() (065/057) and tracebackSurvivors() from
 * ../viterb00.c. gett/toggle are checked against the *_golden_hamming.dat
 * references; zeros/ones against the stock goldens.
 *
 * Build (from viterb00/test):
 *   cc -O2 -std=c99 -I stub -I .. legb_check.c ../viterb00.c -o legb_check
 *   ./legb_check            (expects rtl_gett.txt, rtl_toggle.txt,
 *                            rtl_ones.txt, rtl_zeros.txt in the cwd)
 */
#include <stdio.h>
#include <string.h>
#include "algo.h"

#define INF 0xFFFFu
#define NST 32

static n_int tsym(const unsigned int *t, n_int e) { n_int b = e * 2; return (t[b >> 5] >> (b & 31)) & 3; }
static n_int ham(n_int a, n_int b) { n_int x = a ^ b; return (x & 1) + ((x >> 1) & 1); }

static void sw_acs(const e_s16 *in, unsigned int *surv)
{
    const unsigned int *t = computeOutputTable();
    e_u16 acc[NST], nx[NST];
    n_int c, d;
    for (d = 0; d < NST; d++) acc[d] = (e_u16)((d == 0) ? 0 : INF);
    for (c = 0; c < MAX_DATA_SIZE; c++) {
        e_s16 ew = in[c];
        n_int recv = ((((ew & 0x07) < 4) ? 1 : 0) << 1) | ((((ew & 0x38) >> 3) < 4) ? 1 : 0);
        unsigned int w = 0;
        for (d = 0; d < NST; d++) {
            n_int input = (d >> 4) & 1, pa = ((d & 0xf) << 1), pb = pa | 1;
            n_int ea = tsym(t, (input << 5) | pa), eb = tsym(t, (input << 5) | pb);
            unsigned ca = (acc[pa] == INF) ? 0x1FFFFu : (unsigned)acc[pa] + (unsigned)ham(ea, recv);
            unsigned cb = (acc[pb] == INF) ? 0x1FFFFu : (unsigned)acc[pb] + (unsigned)ham(eb, recv);
            n_int sv = (cb < ca) ? 1 : 0;
            unsigned ch = sv ? cb : ca;
            nx[d] = (e_u16)((ch >= INF) ? INF : ch);
            w |= (unsigned)sv << d;
        }
        for (d = 0; d < NST; d++) acc[d] = nx[d];
        surv[c] = w;
    }
}

/* read "<col> <hex>" lines (skip # comments) into surv[0..MAX_DATA_SIZE-1] */
static int load_rtl(const char *path, unsigned int *surv)
{
    FILE *f = fopen(path, "r");
    char line[256];
    int seen = 0;
    if (!f) { printf("  (cannot open %s)\n", path); return -1; }
    for (int i = 0; i < MAX_DATA_SIZE; i++) surv[i] = 0xFFFFFFFFu;
    while (fgets(line, sizeof line, f)) {
        unsigned col, val;
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '#' || *p == '\n' || *p == '\0') continue;
        if (sscanf(p, "%u %x", &col, &val) == 2 && col < MAX_DATA_SIZE) {
            surv[col] = val;
            seen++;
        }
    }
    fclose(f);
    return seen;
}

static int check(const char *name, const char *rtlfile, e_s16 *in, e_s16 *golden)
{
    static unsigned int rtl[MAX_DATA_SIZE], sw[MAX_DATA_SIZE];
    e_s16 out[MAX_DATA_SIZE / 16 + 1];
    int i, n = MAX_DATA_SIZE / 16 + 1;
    int legB_bad = 0, first_col = -1, gold_bad = 0;

    if (load_rtl(rtlfile, rtl) != MAX_DATA_SIZE) {
        printf("  %-14s SKIP (expected %d survivor lines in %s)\n", name, MAX_DATA_SIZE, rtlfile);
        return 1;
    }
    sw_acs(in, sw);

    /* leg B: RTL survivors vs software-model survivors, column for column */
    for (i = 0; i < MAX_DATA_SIZE; i++)
        if (rtl[i] != sw[i]) { if (first_col < 0) first_col = i; legB_bad++; }

    /* decode the RTL survivors through the real traceback, compare to golden */
    tracebackSurvivors(rtl, MAX_DATA_SIZE, out);
    for (i = 0; i < n; i++) if ((out[i] & 0xffff) != (golden[i] & 0xffff)) gold_bad++;

    printf("  %-14s  legB(RTL==sw): %-4s %s   decode-vs-golden: %-4s  (",
           name,
           legB_bad ? "FAIL" : "OK",
           legB_bad ? "" : "            ",
           gold_bad ? "FAIL" : "PASS");
    for (i = 0; i < n; i++) {
        int c1 = (out[i] >> 8) & 0xff, c2 = out[i] & 0xff;
        putchar(c1 >= 32 && c1 < 127 ? c1 : '.');
        putchar(c2 >= 32 && c2 < 127 ? c2 : '.');
    }
    printf(")\n");
    if (legB_bad)
        printf("        -> %d/%d survivor words differ; first at column %d (RTL %08x vs sw %08x)\n",
               legB_bad, MAX_DATA_SIZE, first_col, rtl[first_col], sw[first_col]);
    return (legB_bad || gold_bad) ? 1 : 0;
}

int main(void)
{
    int fail = 0;

    { static e_s16 i[] = {
#include "datasets/zerosi.dat"
      }; static e_s16 g[] = {
#include "datasets/zeros_golden.dat"
      }; fail |= check("zeros", "rtl_zeros.txt", i, g); }

    { static e_s16 i[] = {
#include "datasets/onesi.dat"
      }; static e_s16 g[] = {
#include "datasets/ones_golden.dat"
      }; fail |= check("ones", "rtl_ones.txt", i, g); }

    { static e_s16 i[] = {
#include "datasets/getti.dat"
      }; static e_s16 g[] = {
#include "datasets/gett_golden_hamming.dat"
      }; fail |= check("gett(hamming)", "rtl_gett.txt", i, g); }

    { static e_s16 i[] = {
#include "datasets/togglei.dat"
      }; static e_s16 g[] = {
#include "datasets/toggle_golden_hamming.dat"
      }; fail |= check("toggle(hamming)", "rtl_toggle.txt", i, g); }

    printf("\n%s\n", fail ? "RESULT: see failures above"
                          : "RESULT: RTL survivors == sw_acs, and RTL decode matches all goldens");
    return fail;
}
