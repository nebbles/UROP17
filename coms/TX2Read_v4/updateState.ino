// updateState() takes an existing or new command (stored in struct 'command'
// and updates the state of the motors. This state will be acted on by the
// action() function which calls this function.
//
// This ensures that the motors are not always updated with a new command.
//

void updateState() {
  if ( command.motor < -2 || command.motor > 2 ) {
    Serial.println("command.motor is out of range. Setting as default '0'");
    command.motor = 0;
  }

  // DEBUG
  //  if ( command.motor == -1 ) {
  //    Serial.println("-1 means no motor is selected");
  //  }

  switch (command.motor) {
    case -2:
      stepper1.setAcceleration(command.mspeed);
      stepper2.setAcceleration(command.mspeed);
      Serial.print("Acceleration for both motors changed to: ");
      Serial.println(command.mspeed);
      command.motor = -1; // Set ongoing command to null
      break;

    case -1:
      // This case is null. Nothing is changed/affected.
      break;

    case 0: // both motors are chosen
      motorstate.Aspeed = command.mspeed;
      motorstate.Bspeed = command.mspeed;
      break;

    case 1: // only motor A
      motorstate.Aspeed = command.mspeed;
      break;

    case 2: // only motor B
      motorstate.Bspeed = command.mspeed;
      break;
  }
}

