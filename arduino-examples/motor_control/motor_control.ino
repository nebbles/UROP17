/*
  LED / STEPPER
  Author: Benedict Greenberg
  Date: 31/07/15

  Program runs with LEDs to simulate stepper motor.
  Power supplied externally to stepper motor drivers.

  Stepper motors will be controlled over serial.
  They need to execute steps one in turn to emulate simultaneous control.

  Wiring set-up as follows:

  STEP MOTOR 28BYJ-48 (5V DC) -> Arduino Duo Digital GPIO
  IN1 -> 8
  IN2 -> 9
  IN3 -> 10
  IN4 -> 11

*/

// Define pins for stepper motor 1
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

int led = 13; // built in LED
int serialData = 0; // variable used for serial data
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
