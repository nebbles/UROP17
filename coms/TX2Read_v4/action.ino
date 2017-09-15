// action() calls the updateState() function and then applies target
// positions for each or both motors to move to.
//

void action() {

  updateState();

  // Check the motor states and act accordingly

  // Update target positions
  stepper1.moveTo(motorstate.Aspeed);
  stepper2.moveTo(motorstate.Bspeed);

//motorstate.Bspeed == 0 || 

  if (stepper1.distanceToGo() == 0) {
    stepper1.stop();
    stepper1.disableOutputs();
  }
  else {
    stepper1.enableOutputs();
    stepper1.run();
  }

  if (stepper2.distanceToGo() == 0) {
    stepper2.stop();
    stepper2.disableOutputs();
  }
  else {
    stepper2.enableOutputs();
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
