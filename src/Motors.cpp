#include "Motors.h"


bool Motors::Init()
{
    int motorPins[] = {M1_PIN, M2_PIN, M3_PIN, M4_PIN};
    k = 1;
    for (byte i = 0; i<PROPS; i++)
    {
        propellers[i] = Propeller();
        propellers[i].Init(motorPins[i]);
        
    }
    return true;
}

float Sigmoid(float input){
  return 1.0/(1.0 + exp(-input));
}

void Motors::Main()
{
    propellers[0].value = (idleOffset[0] + throttle + motorYpr[2] + motorYpr[1] + motorYpr[0]) * k;
    propellers[1].value = (idleOffset[1] + throttle + motorYpr[2] - motorYpr[1] - motorYpr[0]) * k;
    propellers[2].value = (idleOffset[2] + throttle - motorYpr[2] - motorYpr[1] + motorYpr[0]) * k;
    propellers[3].value = (idleOffset[3] + throttle - motorYpr[2] + motorYpr[1] - motorYpr[0]) * k;

    for (byte i = 0; i < 4; i++){
      if (propellers[i].value > 1000) propellers[i].value = 1000;
      if (propellers[i].value < 0) propellers[i].value = 0;
      outputsRead[i] = propellers[i].readVal;
    }
    for (int i = 0; i < 4; i++){
      propellers[i].Main();
    }
}
