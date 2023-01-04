#include "Filter.h"

float Filter::MovingAvg(int sensVal, int bufferSize)
{
    float sum = 0;
    for (int i = 0; i < bufferSize; i++)
    {
        filterBuffer[i] = (i < bufferSize - 1) ? filterBuffer[i+1] : sensVal;
        sum += filterBuffer[i];
    }

    return sum / bufferSize;
}

float Filter::StochMovingAvg(float sensVal, int bufferSize)
{
    float sum = 0;
    for (int i = 0; i < bufferSize; i++)
    {
        filterBuffer[i] = (i < bufferSize - 1) ? filterBuffer[i+1] : sensVal;
        sum += filterBuffer[i] * (i + 1);
    }

    return sum / (bufferSize * (bufferSize - 1) / 2);
}
