#include <Arduino.h>
#include<Servo.h>

class Propeller
{
    private:
        int _pin;
        int _lowerPulse;
        int _upperPulse;
        int _escVal;
        bool isAttached;
        Servo ESC;
    public:
        float value;
        float readVal;
        Propeller();
        void Init(int pin);
        void Main();
};
