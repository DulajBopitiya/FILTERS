#include <DIGITAL_RCLPF.h>

void RCFFilter_Init(RCFilter *filter, float cutoffFreqHz , float sampleFreqHz) {

    float RC = 1.0f / (cutoffFreqHz * 2.0f * 3.14159265358979323846f);
    float dt = 1.0f / sampleFreqHz;
    filter->coeff[0] = dt / (RC + dt);
    filter->coeff[1] = RC / (RC + dt);
    filter->out[0] = 0.0f;
    filter->out[1] = 0.0f;
}


void RCFILTER_Update(RCFilter *filter, float input) {

    // Apply the filter
    filter->out[0] = filter->coeff[0] * input + filter->coeff[1] * filter->out[1];
    
    // Update the previous output
    filter->out[1] = filter->out[0];
    
    // Return the filtered value
    return filter->out[0];
}