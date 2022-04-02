#include <Arduino.h>
#include "DRV8825.h"
#include "define.h"

DRV8825 stepper1(MOTOR_STEPS, ONEDIR, ONESTEP, ONEMS0, ONEMS1, ONEMS2);
DRV8825 stepper2(MOTOR_STEPS, TWODIR, TWOSTEP, TWOMS0, TWOMS1, TWOMS2);
DRV8825 stepper3(MOTOR_STEPS, THREEDIR, THREESTEP, THREEMS0, THREEMS1, THREEMS2);

void setup() {
  stepper1.begin(10, 32);         // rpm, microstepping
  stepper2.begin(3, 32);       
  stepper3.begin(10, 32);        
  Serial.begin(115200);

}

void loop() {
    // Tell motor to rotate 360 degrees. That's it.
  if (Serial.available() > 0) {
    int val = Serial.parseInt();
    if (val != 0) {
      Serial.print("I got: ");
      Serial.println(val, DEC);
      //stepper1.rotate(90);
      stepper2.rotate(90);
      //stepper3.rotate(90);
      Serial.flush();
    }
  }
}
