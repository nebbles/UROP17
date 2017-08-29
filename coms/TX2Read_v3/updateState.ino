// updateState takes a known or new command and updates the
// semi-permanent state of the motors.
//
// This ensures that the motors are not always updated with a new command.
//

void updateState() {
  if ( command.motor < 0 || command.motor > 2 ) {
    Serial.println("command.motor is out of range. Setting as default '0'");
    command.motor = 0;
  }

  switch (command.motor) {

    case 0: // both motors are chosen
      if (command.mspeed == 0) {
        motorstate.Aspeed = 0;
        motorstate.Bspeed = 0;
      }
      else {
        motorstate.Aspeed = command.mspeed;
        motorstate.Bspeed = command.mspeed;
      }
      break;

    case 1: // only motor A
      if (command.mspeed == 0) {
        motorstate.Aspeed = 0;
      }
      else {
        motorstate.Aspeed = command.mspeed;
      }
      break;

    case 2: // only motor B
      if (command.mspeed == 0) {
        motorstate.Bspeed = 0;
      }
      else {
        motorstate.Bspeed = command.mspeed;
      }
      break;
  }
}

