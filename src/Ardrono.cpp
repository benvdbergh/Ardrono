#include <Arduino.h>
#include <Firmata.h>

#include "Motion.h"
#include "Motors.h"
#include "Controller.h"

Motion motion;
Controller controller;
Motors motors;
byte mode;

float setpoint[3] = {0, 0, 0}; //[yaw pitch roll]
float db[12] = {};

void analogReadCallback(byte tpc, int value){
  db[tpc] = value;
}


void setup() {
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogReadCallback);
  Firmata.begin(57600);


  motors.Init();
  motion.Init();
  float pids[9];
  controller.TunePitchRoll(pids);
}

void loop() {
  // Read Host data
  while (Firmata.available()) {
    Firmata.processInput();
  }

  // Get MPU sensor data
  motion.Main();

  db[YAW] = motion.ypr[0]*10;
  db[PITCH] = motion.ypr[1]*10;
  db[ROLL] = motion.ypr[2]*10;

  // Set setpoint based on mode
  switch (mode){
    case 0:     // Manual
      motors.motorYpr[0] = db[SET_YAW];
      motors.motorYpr[1] = db[SET_PITCH];
      motors.motorYpr[2] = db[SET_ROLL];
      motors.throttle = db[SET_THROTTLE];
      break;

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
      motors.throttle = 0.0;
      break;
  }

  // calculate motor outputs
  controller.YprController(setpoint, motion.ypr, motors.motorYpr);

  // Write motorvalues to ESC's
  motors.Main();

  // Receive and send new debug info from/to host
  while (Firmata.available()) {
    Firmata.processInput();
  }

  for (byte i = 0; i < 12; i++){
    Serial.print(db[i]);
    Serial.print("\t");
  }
  
  Serial.println();

  // Firmata.sendAnalog(yaw, motion.ypr[0])
}
