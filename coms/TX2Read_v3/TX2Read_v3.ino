// TX2Read
// Program by BG.
// 25 August 2017
//
// Communication received from Nvidia TX2 running TX2Write or newer.
// Controlling 28BYJ-48 Stepper Motor with ULN2003 driver.
//
#include <AccelStepper.h> // advanced Stepper lib on Arduino
#define HALFSTEP 8

// Motor pin definitions
#define motorAPin1  3     // IN1 on the ULN2003 driver 1
#define motorAPin2  4     // IN2 on the ULN2003 driver 1
#define motorAPin3  5     // IN3 on the ULN2003 driver 1
#define motorAPin4  6     // IN4 on the ULN2003 driver 1

#define motorBPin1  8     // IN1 on the ULN2003 driver 2
#define motorBPin2  9     // IN2 on the ULN2003 driver 2
#define motorBPin3  10    // IN3 on the ULN2003 driver 2
#define motorBPin4  11    // IN4 on the ULN2003 driver 2

// Initialize with pin sequence IN1-IN3-IN2-IN4
// for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorAPin1, motorAPin3, motorAPin2, motorAPin4);
AccelStepper stepper2(HALFSTEP, motorBPin1, motorBPin3, motorBPin2, motorBPin4);

char inChar; // character received over Serial
String inString; // cumulative characters saved as String
int number; // value of converted string

struct command_structure { // stores two elements that make up command
  int motor = 0; // motor being controlled, 0 is for both.
  int mspeed = 0; // speed that motor should set to
};
command_structure command; // construct object of struct
int cm_idx = 0; // command number for strings of commands

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for Serial to establish
  }
  Serial.println("TX2Read v3");
  Serial.println("CHECK motors are correctly connected.");
  Serial.println(" ");

  // Establish initial settings for motors
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(2000);
  stepper1.setSpeed(2000);
  stepper1.moveTo(20000);
  stepper1.run();

  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(2000);
  stepper2.setSpeed(2000);
  stepper2.moveTo(20000);
  stepper2.run();

  stepper1.stop();
  stepper1.disableOutputs();
  stepper2.stop();
  stepper2.disableOutputs();
}

void loop() {
  if (Serial.available() > 0) {
    getSerial();
    // TODO; add a getCommand which updates speeds of motors independently
  }
  action(); // TODO; remove dependency on the command struct, independent motor speeds
}


