#include "FIR_FILTER.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {};

void FIRFilter_Init(FIRFilter *filter)
{
    // Initialize the FIR filter structure
    for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++)
    {
        filter->buf[i] = 0.0f; // Initialize the buffer to zero
    }
    filter->bufIndex = 0; // Reset the buffer index
    filter->out = 0.0f;   // Initialize output to zero
}

float FIRFilter_Update(FIRFilter *filter, float input)
{
    // Update the FIR filter with a new input sample
    filter->buf[filter->bufIndex] = input; // Store the new input in the buffer

    filter->bufIndex++; // Increment the buffer index

    // Ensure the buffer index wraps around if it exceeds the buffer length
    if (filter->bufIndex >= FIR_FILTER_LENGTH)
    {
        filter->bufIndex = 0; // Wrap around if the index exceeds the buffer length
    }

    // Calculate the output using the FIR impulse response
    filter->out = 0.0f;

    uint8_t sumIndex = filter->bufIndex; // Start from the current index

    for (uint8_t i = 0; i < FIR_FILTER_LENGTH; i++)
    {
        if (sumIndex > 0){
            sumIndex--;
        }
        else{
            sumIndex = FIR_FILTER_LENGTH - 1; // Wrap around to the end of the buffer
        }

        // Accumulate the weighted sum of the buffer values using the FIR impulse response
        filter->out += FIR_IMPULSE_RESPONSE[i] * filter->buf[sumIndex];
    }
    return filter->out; // Return the computed output
}