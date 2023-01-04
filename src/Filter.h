#include "Definitions.h"

class Filter
{
    private:
        float filterBuffer[MA_BUFFER];
    public:
        float MovingAvg(int sensVal, int bufferSize);
        float StochMovingAvg(float sensVal, int bufferSize);
        
};
