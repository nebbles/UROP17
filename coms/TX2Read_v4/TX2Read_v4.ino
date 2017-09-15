// TX2Read
// Program by BG.
// v3: 25 August 2017
// v4: 05 September 2017
//
// Communication received from Nvidia TX2 running TX2Write or newer.
// Controlling 28BYJ-48 Stepper Motor with ULN2003 driver.
//
// v4:
// - set motor (M) to position (P) with call command "M,P."
//      M = -1 selects no motors
//      M = 0 selects both motors
//      M = 1 selects motor A
//      M = 2 selects motor B
//      P can = any Real Integer value
// - call "stop" over serial to shutdown both motors
// - call "a" over serial to shutdown motor A immediately
// - call "b" over serial to shutdown motor B immediately
//

#include <AccelStepper.h> // advanced Stepper lib on Arduino
#define HALFSTEP 8 // required by AccelStepper

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

struct motor_states_struct { // stores the semi-permanent state of motors
  int Aspeed = 0;
  int Bspeed = 0;
};
motor_states_struct motorstate; // construct object

void stopAll() {
  stepper1.stop();
  stepper1.disableOutputs();
  stepper2.stop();
  stepper2.disableOutputs();
  command.motor = -1; // Set ongoing command to neither motor
}
void stopA() {
  stepper1.stop();
  stepper1.disableOutputs();
  command.motor = -1; // Set ongoing command to neither motor
}
void stopB() {
  stepper2.stop();
  stepper2.disableOutputs();
  command.motor = -1; // Set ongoing command to neither motor
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for Serial to establish
  }
  Serial.println("TX2Read v4");
  Serial.println("CHECK MOTORS are correctly connected.");
  Serial.println(" ");
  Serial.println("Motor A: IN1-4 connected to DIGITAL 3-6");
  Serial.println("Motor B: IN1-4 connected to DIGITAL 8-11");
  Serial.println(" ");

  { // Stepper motor setup sequence
    // Establish initial settings for motors

    int maxspeed = 1500;
    int maxaccel = 1500;

    stepper1.setMaxSpeed(maxspeed);
    stepper1.setSpeed(maxspeed);
    stepper1.setAcceleration(maxaccel);

    stepper2.setMaxSpeed(maxspeed);
    stepper2.setSpeed(maxspeed);
    stepper2.setAcceleration(maxaccel);

    stepper1.run();
    stepper2.run();
    stopAll();
  }

}

void loop() {
  if (Serial.available() > 0) {
    getSerial();
    // TODO; add a way to change motor settings
  }
  action();
}


