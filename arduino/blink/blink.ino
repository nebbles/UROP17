/*
  LED / STEPPER
  Author: Benedict Greenberg
  Date: 31/07/15

  Program runs with LEDs to simulate stepper motor.
  Power supplied externally to stepper motor drivers.

  Stepper motors will be controlled over serial.
  They need to execute steps one in turn to emulate simultaneous control.

*/
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 12 is another GPIO pin that can be use, seperate from the built in board.
// give it a name:
int led = 12;
int serialData = 0;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
