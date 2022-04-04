//###################################################
//###################################################
//
//####     ####
//#  #     #  #      ######  ######## ########
//#  ####  #  ####   #    ## #  ##  # #  ##  #
//#     ## #     ##  ####  # #  ##  # #  ##  #
//#  ##  # #  ##  # ##     # #  ##  # #  ##  #
//#  ##  # #  ##  # #  ##  # #  ##  # ##    ##
//#     ## #     ## ##     # ##     #  ##  ##
// # ####   # ####   #######  #######   ####    
//
//
//BBASV 3.0 ball shooter board prototype 1
//Firmware Version :  v1.0
//
// Written by Titus for AUV 3.0 Ball shooter 
//
// Test code for cocking motors on stepper 3 and 4 slot
// Stepper 2 & 3: Cocking motors 
// Stepper 4: Drum steppers 
// Servo 1: Firing servo 
// Servo 2: Drum continuous servo 
// 
//###################################################
//###################################################

#include <Servo.h> 
#include "define.h"

Servo fire;
Servo drum;

bool is_locked;

void setup() {
  // Declare pins as output:
  //stepper 4
  pinMode(dir4cock, OUTPUT);
  pinMode(step4cock, OUTPUT);
  pinMode(MS14, OUTPUT);
  pinMode(MS24, OUTPUT);
  
  // stepper 3
  pinMode(dir3cock, OUTPUT);
  pinMode(step3cock, OUTPUT);
  pinMode(MS13, OUTPUT);
  pinMode(MS23, OUTPUT);

  // stepper 2
  pinMode(dir2cock, OUTPUT);
  pinMode(step2cock, OUTPUT);
  pinMode(MS12, OUTPUT);
  pinMode(MS22, OUTPUT);

  // set to 1/16 microstep
  digitalWrite(MS12, HIGH);
  digitalWrite(MS22, HIGH);  
  digitalWrite(MS13, HIGH);
  digitalWrite(MS23, HIGH);
  digitalWrite(MS14, HIGH);
  digitalWrite(MS24, HIGH);

  // Initialize servos
  fire.attach(servo1);
  drum.attach(servo2);
  
  Serial.begin(115200);
  print_instructions();
}

void print_instructions() {
  Serial.println("ASV 3.0 Ball Shooter:");
  Serial.println("1: Cock motors");
  Serial.println("2: Reset cocking motors");
  Serial.println("3: Reload drum");
  Serial.println("4: Fire");
  Serial.println("5: Toggle drum state");
}

void cock_motors() {  
    digitalWrite(dir2cock, HIGH);
    digitalWrite(dir3cock, HIGH);
    for (int i = 0; i < stepsPerRevolution * microstep * 5; i++) {
      digitalWrite(step3cock, HIGH);
      digitalWrite(step4cock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(step3cock, LOW);
      digitalWrite(step4cock, LOW);
      delayMicroseconds(stepperdelay);
    }
}

void reset_motors() {
    digitalWrite(dir2cock, LOW);
    digitalWrite(dir3cock, LOW);
    for (int i = 0; i < stepsPerRevolution * microstep * 5; i++) {
      digitalWrite(step3cock, HIGH);
      digitalWrite(step4cock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(step3cock, LOW);
      digitalWrite(step4cock, LOW);
      delayMicroseconds(stepperdelay);
    }
}

void reload_drum() {
    digitalWrite(dir2cock, LOW);
    for (int i = 0; i < stepsPerRevolution * microstep * 0.25; i++) {
      digitalWrite(step2cock, HIGH);
      delayMicroseconds(stepperdelay);
      digitalWrite(step2cock, LOW);
      delayMicroseconds(stepperdelay);
    }
}

void fire_ball() {
  //fire.write();
}

bool toggledrum() {
  if (is_locked) {
//    drum.write();     // unlock
    is_locked = false;
  } else {
//    drum.write();     // lock
    is_locked = true;
  }
}

void loop() {
    if (Serial.available() > 0) {
      int val = Serial.parseInt();
      switch(val) {
        case 1: {
          Serial.println("Cocking motors...");
          cock_motors();
          print_instructions();
          break;
        }
        case 2: {
          Serial.println("Resetting cocking motors...");
          reset_motors();
          print_instructions();
          break;
        }
        case 3: {
          Serial.println("Reloading Drum...");
          reload_drum();
          print_instructions();
          break;
        }
        case 4: {
          Serial.println("FIREEEEE");
          fire_ball();
          print_instructions();
          break;
        }
        case 5: {
          Serial.println("Toggling Drum State...");
          toggledrum();
          print_instructions();
          break;
        }
        default:
          break;
      }
    }
    delay(100);
}
