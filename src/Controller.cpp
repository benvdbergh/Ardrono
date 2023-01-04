#include "Controller.h"
#include <Arduino.h>

float PID::Regulate(float sensVal, float setPoint){
    err = sensVal - setPoint;

    float P_out = err * Kp;
    float I_out = mem_I_out + err * Ki;
    float D_out = (err - mem_err) * Kd;

    mem_I_out = I_out;
    mem_err = err;

    return P_out + I_out + D_out;
}

void Controller::Init(){

}

void Controller::YprController(float setPoint[], float sensYpr[], float motorYpr[])
{
    for (byte i = 0; i < 3; i++)
    {
        motorYpr[i] = controllers[i].Regulate(sensYpr[i], setPoint[i]);
    }
}

void Controller::ThrottleController(float setPoint, float sensVal, float &motorThrottle)
{
    motorThrottle = throtController.Regulate(sensVal, setPoint);
}

void Controller::Tune(int nr, float param[])
{
    // nr: 0=yaw  1=pitch  2=roll 
    controllers[nr].Kp = param[0];
    controllers[nr].Ki = param[1];
    controllers[nr].Kp = param[2];

    Serial.print("PID tune: ");
    Serial.print(param[0]);
    Serial.print("\t");
    Serial.print(param[1]);
    Serial.print("\t");
    Serial.print(param[2]);
    Serial.println("\t");
}
void Controller::TunePitchRoll(float param[])
{
    controllers[1].Kp = param[0];
    controllers[1].Ki = param[1];
    controllers[1].Kp = param[2];
    controllers[2].Kp = param[0];
    controllers[2].Ki = param[1];
    controllers[2].Kp = param[2];
}
void Controller::TuneThrottle(float param[])
{
    controllers[3].Kp = param[0];
    controllers[3].Ki = param[1];
    controllers[3].Kp = param[2];
}
