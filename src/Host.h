#include "Definitions.h"
#include <Firmata.h>
#include <Wire.h>

#define I2C_WRITE                   B00000000
#define I2C_READ                    B00001000
#define I2C_READ_CONTINUOUSLY       B00010000
#define I2C_STOP_READING            B00011000
#define I2C_READ_WRITE_MODE_MASK    B00011000
#define I2C_10BIT_ADDRESS_MODE_MASK B00100000
#define I2C_END_TX_MASK             B01000000
#define I2C_STOP_TX                 1
#define I2C_RESTART_TX              0
#define I2C_MAX_QUERIES             8
#define I2C_REGISTER_NOT_SPECIFIED  -1

// the minimum interval for sampling analog input
#define MINIMUM_SAMPLING_INTERVAL   1
class Host
{
    private:
        

    public:
        // float idleOffset[PROPS] = {3, 3, 3, 3};
        // float throttle;
        // int k;
        // float motorYpr[3];
        // float outputsRead[4];
        bool Init();
        void Main();
};
