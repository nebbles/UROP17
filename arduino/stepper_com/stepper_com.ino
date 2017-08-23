#include <AccelStepper.h>
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

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorAPin1, motorAPin3, motorAPin2, motorAPin4);
AccelStepper stepper2(HALFSTEP, motorBPin1, motorBPin3, motorBPin2, motorBPin4);

String inString = ""; // string to hold input
float value = 0.00; // float to hold current speed & acceleration setting

int input,num;
int buff[5];
int j=-1;

void setup() {
  Serial.begin(9600);
  while(!Serial){;} // wait for serial port
  Serial.println("Serial connected");
  Serial.println("Communication from CPP to Motors is running.");
  
  stepper1.setMaxSpeed(2000.0);
  stepper1.setAcceleration(2000.0);
  stepper1.setSpeed(2000);
  stepper1.moveTo(20000);
  stepper1.run();

  stepper2.setMaxSpeed(2000.0);
  stepper2.setAcceleration(2000.0);
  stepper2.setSpeed(2000);
  stepper2.moveTo(20000);
  stepper2.run();

}//--(end setup )---


int calc()
{
    int num=0;

    for(int x=0;x<=j;x++)
          num=num+(buff[x]-48)*pow(10,j-x);

    return num;
}

void action() 
{
  if (value == 0.0) {
    stepper1.stop();
    stepper1.disableOutputs();
    stepper2.stop();
    stepper2.disableOutputs();
  }
  else {
    stepper1.enableOutputs();
    stepper2.enableOutputs();
  }
  stepper1.setSpeed(value);
  stepper2.setSpeed(value);
  
  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
  
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(-stepper2.currentPosition());
  }
  stepper2.run();
}

void loop() {

  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();

    if (inChar != '\n') { 

      // As long as the incoming byte
      // is not a newline,
      // convert the incoming byte to a char
      // and add it to the string
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value as a float:
    else {
      Serial.print("Input string: ");
      Serial.print(inString);
      Serial.print("\tAfter conversion to float:");
      Serial.println(inString.toFloat());
      value = inString.toFloat();
      // clear the string for new input:
      inString = "";

      Serial.print("Speed has now changed to: ");
      Serial.println(value);

      
    }
  }

  action()
}
