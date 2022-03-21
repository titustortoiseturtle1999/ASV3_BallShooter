/*Example sketch to control a stepper motor with A4988 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dircock1 A0
#define stepcock1 A1
#define dircock2 A2
#define stepcock2 A3
#define dirdrum A4
#define stepdrum A5
#define stepsPerRevolution 800

int stepperdelay = 2000;

void setup() {
  // Declare pins as output:
  pinMode(dircock1, OUTPUT);
  pinMode(stepcock1, OUTPUT);
  pinMode(dircock2, OUTPUT);
  pinMode(stepcock2, OUTPUT);
  pinMode(dirdrum, OUTPUT);
  pinMode(stepdrum, OUTPUT);
}

void loop() {
  int val = 3;
  switch (val) {
    case 1: {
      // spin cocking motors clockwise
      digitalWrite(dircock1, HIGH);
      digitalWrite(dircock2, HIGH);
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepcock1, HIGH);
        digitalWrite(stepcock2, HIGH);
        delayMicroseconds(stepperdelay);
        digitalWrite(stepcock1, LOW);
        digitalWrite(stepcock2, HIGH);
        delayMicroseconds(stepperdelay);
      }
      break;
    }
    case 2: {
      // spin cocking motors counterclockwise
      digitalWrite(dircock1, HIGH);
      digitalWrite(dircock2, HIGH);
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepcock1, HIGH);
        digitalWrite(stepcock2, HIGH);
        delayMicroseconds(stepperdelay);
        digitalWrite(stepcock1, LOW);
        digitalWrite(stepcock2, HIGH);
        delayMicroseconds(stepperdelay);
      }
      break;
    }
    case 3: 
      // spin drum motor clockwise 
      digitalWrite(dirdrum, HIGH);
      for (int i = 0; i < stepsPerRevolution/4; i++) {
        digitalWrite(stepdrum, HIGH);
        delayMicroseconds(stepperdelay);
        digitalWrite(stepdrum, LOW);
        delayMicroseconds(stepperdelay);
      }
      break;
    }      
    digitalWrite(dirdrum, LOW);
    digitalWrite(stepdrum, LOW);
    delay(5000);
}
