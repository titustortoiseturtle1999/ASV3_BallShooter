// Test sketch for tmc 2209 on stepper 3 slot 

// Define stepper motor connections and steps per revolution:
#define dircock 7
#define stepcock 6
#define MS1 28
#define MS2 29
#define stepsPerRevolution 200
#define microstep 16

int stepperdelay = 1000;

void setup() {
  // Declare pins as output:
  pinMode(dircock, OUTPUT);
  pinMode(stepcock, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(30, OUTPUT);
digitalWrite(30, LOW);  
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
}

void loop() {
    digitalWrite(dircock, HIGH);
    for (int i = 0; i < stepsPerRevolution * microstep / 4; i++) {
      digitalWrite(stepcock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(stepcock, LOW);
      delayMicroseconds(stepperdelay);
    }
    digitalWrite(stepcock, LOW);
    delay(3000);
}
