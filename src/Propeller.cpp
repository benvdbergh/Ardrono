#include<Arduino.h>
#include "Propeller.h"
#include<Servo.h>

Propeller::Propeller(){}

void Propeller::Init(int pin){
	_pin = pin;
  Serial.print("Init pin: "); 
  Serial.println(pin);
  _lowerPulse = 1100;
  _upperPulse = 1800;
	this->ESC.attach(_pin,_lowerPulse,_upperPulse);
  isAttached = false;
	while (!isAttached){
		isAttached = this->ESC.attached();
	}
	Serial.println("Prop attached");
}


void Propeller::Main(){
	if (this->ESC.attached()){
		_escVal = map(value, 0, 1000, _lowerPulse, _upperPulse);
    	this->ESC.writeMicroseconds(_escVal);
  } 
  else {
  	_escVal = 0;
		// Serial.println("Prop not attached");
  }

	readVal = ESC.readMicroseconds();
}
