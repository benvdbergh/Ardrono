#include <Arduino.h>
#include "Motion.h"
#include "Motors.h"
#include "Controller.h"
#include "Filter.h"

Motion motion;
Controller controller;
Motors motors;
Filter filterX, filterY, filterZ, filterK;

float setpoint[3] = {0, 0, 0}; //[yaw pitch roll]
float data[3] = {1.0, 0.0, 3.4};

void setup() {
  Serial.begin(57600);
  motors.Init();
  motion.Init();
  float pids[9];
  controller.TunePitchRoll(pids);
}

void loop() {
  // Get MPU sensor data
  motion.Main();

  // Set setpoint based on mode
  switch (1){
    case 1:     // Stabilize
      setpoint[0] = 0;
      setpoint[1] = 0;
      setpoint[2] = 0;
      controller.ThrottleController(0, motion.aaReal.y, motors.throttle);
      break;
    
    case 4:     // Idle
      motors.motorYpr[0] = 0.0;
      motors.motorYpr[1] = 0.0;
      motors.motorYpr[2] = 0.0;
      break;
  }

  // calculate motor outputs
  controller.YprController(setpoint, motion.ypr, motors.motorYpr);

  // Write motorvalues to ESC's
  motors.Main();
}
