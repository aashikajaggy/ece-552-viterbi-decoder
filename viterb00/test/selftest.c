/*
 * Standalone correctness test for ViterbiDecoderIS136.
 *
 * Checks the decoder against all four shipped datasets without needing the
 * full EEMBC harness. See README in this directory for build/run commands,
 * or just run:  make -C test   (from the viterb00/ directory).
 *
 * Exits 0 if every dataset matches its golden output, 1 otherwise.
 */
#include <stdio.h>
#include "algo.h"

void ViterbiDecoderIS136(e_s16 *EncodedStreamPtr, e_s16 *DecodedStreamPtr);

/* Same CRC16 the EEMBC harness uses (th_lite/src/crc.c), so a pass here
 * means a pass under NON_INTRUSIVE_CRC_CHECK too. */
static e_u16 crc8(e_u8 d, e_u16 c) {
    int i; e_u8 x, carry;
    for (i = 0; i < 8; i++) {
        x = (e_u8)((d & 1) ^ ((e_u8)c & 1)); d >>= 1;
        if (x == 1) { c ^= 0x4002; carry = 1; } else carry = 0;
        c >>= 1;
        if (carry) c |= 0x8000; else c &= 0x7fff;
    }
    return c;
}
static e_u16 crc16(e_u16 d, e_u16 c) {
    c = crc8((e_u8)(d & 0xFF), c);
    c = crc8((e_u8)((d & 0xFF00) >> 8), c);
    return c;
}

static int run(const char *name, e_s16 *in, e_s16 *golden)
{
    e_s16 out[MAX_DATA_SIZE/16 + 1];
    int i, n = MAX_DATA_SIZE/16 + 1, bad = 0;
    e_u16 crc = 0;

    ViterbiDecoderIS136(in, out);

    for (i = 0; i < n; i++) {
        crc = crc16((e_u16)out[i], crc);
        if (out[i] != golden[i]) {
            if (bad < 4)
                printf("    word %2d: got %04x  expected %04x\n",
                       i, (unsigned)(out[i] & 0xffff), (unsigned)(golden[i] & 0xffff));
            bad++;
        }
    }

    printf("  %-8s %-9s crc=%04x  (", name, bad ? "FAIL" : "PASS", crc);
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
      }; fail |= run("zeros", i, g); }

    { static e_s16 i[] = {
        #include "datasets/onesi.dat"
      }; static e_s16 g[] = {
        #include "datasets/ones_golden.dat"
      }; fail |= run("ones", i, g); }

    { static e_s16 i[] = {
        #include "datasets/getti.dat"
      }; static e_s16 g[] = {
        #include "datasets/gett_golden.dat"
      }; fail |= run("gett", i, g); }

    { static e_s16 i[] = {
        #include "datasets/togglei.dat"
      }; static e_s16 g[] = {
        #include "datasets/toggle_golden.dat"
      }; fail |= run("toggle", i, g); }

    printf("\n%s\n", fail ? "RESULT: FAIL" : "RESULT: all datasets pass");
    return fail;
}
