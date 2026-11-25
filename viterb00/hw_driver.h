/*
 * hw_driver.h
 * C-callable interface to the Verilator-compiled viterbi_accelerator model.
 */
#ifndef HW_DRIVER_H
#define HW_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Construct the model and run the reset sequence. Call once before use. */
void hw_init(void);


void hw_init_frame(const unsigned int seed_metrics[32], const unsigned int table[4]);

/* Run ONE ACS column (one trellis stage) via the start strobe. */
unsigned int hw_run_column(unsigned char received);

/* Run final blocks and free the model. Call once when done. */
void hw_final(void);

#ifdef __cplusplus
}
#endif

#endif /* HW_DRIVER_H */
