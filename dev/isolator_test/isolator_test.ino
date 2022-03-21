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
//BBASV 3.0 ball shooter board
//Firmware Version :  v1.0
//
// Written by Titus for ASV 3.0 Ball shooter 
// Test code for isolators 
//
// TMC 2209 drivers are connected to Serial 1 
//###################################################
//###################################################

// Stepper setup 
const int stepper1_step = 2;
const int stepper1_dir = 3;
const int stepper2_step = 4;
const int stepper2_dir = 5;
const int stepper3_step = 6;
const int stepper3_dir = 7;
const int stepper4_step = 8;
const int stepper4_dir = 9;
const int stepper5_step = 10;
const int stepper5_dir = 11;

const int stepper1_m0 = 22;
const int stepper1_m1 = 23;
const int stepper1_m2 = 24;
const int stepper2_m0 = 25;
const int stepper2_m1 = 26;
const int stepper2_m2 = 27;
const int stepper3_m0 = 28;
const int stepper3_m1 = 29;
const int stepper3_m2 = 30;
const int stepper4_m0 = 31;
const int stepper4_m1 = 32; 
const int stepper4_m2 = 33;
const int stepper5_m0 = 34;
const int stepper5_m1 = 35;
const int stepper5_m2 = 36;

// servo setup 
int test = 44;
const int servo1;
void setup() {
  Serial.begin(115200);
  for (int i = 2; i < 15; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 22; i < 37; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
//  if (Serial.available() > 0) {
//    int val = Serial.parseInt();
    for (int i = 2; i < 15; i++) {
      digitalWrite(i, HIGH);
    }
    for (int i = 22; i < 37; i++) {
      digitalWrite(i, HIGH);
    }
    delay(100);
    for (int i = 2; i < 15; i++) {
      digitalWrite(i, LOW);
    }
    for (int i = 22; i < 37; i++) {
      digitalWrite(i, LOW);
    }
//  }

  Serial.println("working");
  delay(100);
}
