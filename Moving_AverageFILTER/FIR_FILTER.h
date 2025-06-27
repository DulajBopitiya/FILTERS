#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <stdint.h>
#include <Arduino.h>


#define FIR_FILTER_LENGTH 16 // Length of the FIR filter    


typedef struct {
   float buf[FIR_FILTER_LENGTH] // Current index in the output buffer
   uint8_t bufIndex; // Current index in the output buffer

   float out;
} FIRFilter;



void FIRFilter_Init(FIRFilter *filter);
float FIRFilter_Update(FIRFilter *filter, float input);
#endif