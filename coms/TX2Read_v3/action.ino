// action uses the command object
// It applies updated settings to the motor drivers.
//

void action() {
  if ( command.motor < 0 || command.motor > 2 ) {
    Serial.println("command.motor is out of range. Setting as default '0'");
    command.motor = 0;
  }


  switch (command.motor) {
    case 0:
      if (command.mspeed == 0) {
        stepper1.stop();
        stepper1.disableOutputs();
        stepper2.stop();
        stepper2.disableOutputs();
      }
      else {
        stepper1.enableOutputs();
        stepper2.enableOutputs();
        stepper1.setSpeed(command.mspeed);
        stepper2.setSpeed(command.mspeed);
        Serial.println("Both motors set.");

      }
      break;
    case 1:
      //TODO
      if (command.mspeed == 0) {
        stepper1.stop();
        stepper1.disableOutputs();
        Serial.println("Motor 1 stopped.");

      }
      else {
        stepper1.enableOutputs();
        stepper1.setSpeed(command.mspeed);
        Serial.println("Motor 1 set.");

      }
      break;
    case 2:
      //TODO
      if (command.mspeed == 0) {
        stepper2.stop();
        stepper2.disableOutputs();
        Serial.println("Motor 2 stopped.");

      }
      else {
        stepper2.enableOutputs();
        stepper2.setSpeed(command.mspeed);
        Serial.println("Motor 2 set.");

      }
      break;
  }

  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(-stepper2.currentPosition());
  }

  // TODO; these may be causing the issue of motors disobeying stop command.
  stepper1.run();
  stepper2.run();
}
