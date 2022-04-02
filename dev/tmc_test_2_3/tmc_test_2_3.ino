// Test sketch for tmc 2209 on stepper 2 and 3 slot 

// stepper 2 
#define dir2cock 5
#define step2cock 4
#define MS12 25
#define MS22 26
#define stepsPerRevolution 200

// stepper 3
#define dir3cock 7
#define step3cock 6
#define MS13 28
#define MS23 29

#define microstep 16

int stepperdelay = 200;

void setup() {
  // Declare pins as output:
  pinMode(dir3cock, OUTPUT);
  pinMode(step3cock, OUTPUT);
  pinMode(MS13, OUTPUT);
  pinMode(MS23, OUTPUT);
  pinMode(dir2cock, OUTPUT);
  pinMode(step2cock, OUTPUT);
  pinMode(MS12, OUTPUT);
  pinMode(MS22, OUTPUT);

  // set to 1/16 microstep
  digitalWrite(MS12, HIGH);
  digitalWrite(MS22, HIGH);  
  digitalWrite(MS13, HIGH);
  digitalWrite(MS23, HIGH);

}

void loop() {
    digitalWrite(dir2cock, HIGH);
    digitalWrite(dir3cock, HIGH);
    for (int i = 0; i < stepsPerRevolution * microstep * 5; i++) {
      digitalWrite(step2cock, HIGH);
      digitalWrite(step3cock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(step2cock, LOW);     
      digitalWrite(step3cock, LOW);
      delayMicroseconds(stepperdelay);
    }
    delay(1000);
    digitalWrite(dir2cock, LOW);
    digitalWrite(dir3cock, LOW);
    for (int i = 0; i < stepsPerRevolution * microstep * 5; i++) {
      digitalWrite(step2cock, HIGH);
      digitalWrite(step3cock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(step2cock, LOW);     
      digitalWrite(step3cock, LOW);
      delayMicroseconds(stepperdelay);
    }
    delay(1000);
}
