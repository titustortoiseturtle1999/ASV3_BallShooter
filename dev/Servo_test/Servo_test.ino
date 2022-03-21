#include <Servo.h> 

Servo servo1;
  
int val = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(44);
  Serial.begin(115200);

}

void moveServo(int angle) {                                                                                                                                                                                                       
  servo1.write(angle); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    val = Serial.parseInt();
    if (val != 0) {
      Serial.print("I got: ");
      Serial.println(val, DEC);
      moveServo(val);
    }
  }
}
