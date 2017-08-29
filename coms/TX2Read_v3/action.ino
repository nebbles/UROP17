// action uses the 'command' object
// It applies updated settings to the motor drivers.
//

void action() {

  updateState();

  if (motorstate.Aspeed == 0) {
    stepper1.stop();
    stepper1.disableOutputs();
  }
  else if (motorstate.Aspeed != 0) {
    stepper1.enableOutputs();
    stepper1.setSpeed(motorstate.Aspeed);
    stepper1.run();
  }

  if (motorstate.Bspeed == 0) {
    stepper2.stop();
    stepper2.disableOutputs();
  }
  else if (motorstate.Bspeed != 0) {
    stepper2.enableOutputs();
    stepper2.setSpeed(motorstate.Bspeed);
    stepper2.run();
  }

  // Change direction when the stepper reaches the target position
  // This is currently depracated.
  //
  //  if (stepper1.distanceToGo() == 0) {
  //    stepper1.moveTo(-stepper1.currentPosition());
  //  }
  //  if (stepper2.distanceToGo() == 0) {
  //    stepper2.moveTo(-stepper2.currentPosition());
  //  }
}
