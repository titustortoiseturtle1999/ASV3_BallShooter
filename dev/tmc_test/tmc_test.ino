// Test sketch for tmc 2209 on stepper 2 slot 

// Define stepper motor connections and steps per revolution:
#define dircock 5
#define stepcock 4
#define MS1 25
#define MS2 26
#define stepsPerRevolution 200
#define microstep 16

int stepperdelay = 1000;

void setup() {
  // Declare pins as output:
  pinMode(dircock, OUTPUT);
  pinMode(stepcock, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
}

void loop() {
    digitalWrite(dircock, LOW);
    for (int i = 0; i < stepsPerRevolution * microstep / 4; i++) {
      digitalWrite(stepcock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(stepcock, LOW);
      delayMicroseconds(stepperdelay);
    }
    digitalWrite(stepcock, LOW);
    delay(3000);
}
