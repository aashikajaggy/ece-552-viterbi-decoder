/**
 *
 * Copyright (C) EEMBC(R) All Rights Reserved
 *
 * This software is licensed with an Acceptable Use Agreement under Apache 2.0.
 * Please refer to the license file (LICENSE.md) included with this code.
 *
 */

#ifndef __ALGO_H
#define __ALGO_H

/*******************************************************************************
    Includes                                                                    
*******************************************************************************/

#include "thlib.h"

/*******************************************************************************
    Defines
*******************************************************************************/

/* 
 * MAX_DATA_SIZE: the number of bits in the packet which has been encoded by the
 * convolutional encoder. For each bit the Viterbi decoder reads in a pair of
 * branch values.
 *
 * Reasonable values for MAX_DATA_SIZE are in the range 200-400, multiples of 8.
 * The number chosen below is was chosen arbitrarily.
 */

#define     MAX_DATA_SIZE        344   


/* Compile time Data set select for uuencode: 
 * DATA_1 through DATA_4
 * DATA_4 is default
 */ 
#if	(!defined(DATA_1) && !defined(DATA_2) && !defined(DATA_3) && !defined(DATA_4))
#define DATA_4
#endif


void ViterbiDecoderIS136(e_s16 *EncodedStreamPtr, e_s16 *DecodedStreamPtr);

/* RTL/accelerator-convention helpers (see viterb00.c). */
unsigned int *computeOutputTable(void);
e_u16        *computeMetricTable(e_s16 *EncodedStreamPtr);
unsigned int *computeMetricSurvivors(void);

/* Traceback over RTL-convention survivor words -> decoded words (golden layout).
 * tracebackSurvivors() is pure (takes any survivor array); it is what both the
 * hardware path and the software tests use. */
void tracebackSurvivors(const unsigned int *survivors, n_int ncols,
                        e_s16 *DecodedStreamPtr);

/* Hardware ACS path (only real when built with -DUSE_HW_ACCEL; otherwise stubs).
 *   computeACSLoop()       drive the Verilated RTL over the whole frame
 *   getACSSurvivors()      the MAX_DATA_SIZE survivor words it produced
 *   tracebackACSSurvivors() traceback those survivors into DecodedStreamPtr */
void          computeACSLoop(e_s16 *EncodedStreamPtr);
unsigned int *getACSSurvivors(void);
void          tracebackACSSurvivors(e_s16 *DecodedStreamPtr);

#endif /* __ALGO_H */
