#ifndef DIGITAL_RCLPF_H
#define DIGITAL_RCLPF_H

#include <Arduino.h>

typedef struct {
    float coeff[2];  
    float out[2];     
} RCFilter;


//initializes the RC filter with the cutoff frequency and sample frequency
void RCFFilter_Init(RCFilter *filter, float cutoffFreqHz , float sampleFreqHz)


/// Updates the RC filter with a new input value
void RCFILTER_Update(RCFilter *filter, float input);







#endif