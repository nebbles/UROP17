// getSerial performs action to decipher command string sent over USB Serial
//
// Commands should be sent in the format: X,Y.
// where X is an integer for motor
// and Y is an integer for speed

void command_switch() {
  switch (cm_idx) {
    case 0:
      command.motor = number;
      break;
    case 1:
      command.mspeed = number;
      break;
  }
}

void getSerial() {
  inChar = Serial.read(); // read from Serial (1 char at a time)

  if (inChar == ',') { // comma found log command indexes
    number = inString.toInt();
    inString = ""; // clear string now its converted
    command_switch(); // pass number through command switch
    cm_idx++; // iterate command switch

  }
  else if (inChar == '.') {
    number = inString.toInt();
    inString = ""; // clear string now its converted
    command_switch(); // pass number through command switch
    cm_idx = 0; // command has ended, reset command index

    // DEBUG
    //    Serial.println(" ");
    //    Serial.print("  Motor: ");
    //    Serial.println(command.motor);
    //    Serial.print("  Speed: ");
    //    Serial.println(command.mspeed);
  }
  else {
    inString += inChar;
    if (inString == "quit" || inString == "q" || inString == "stop") {
      inString = ""; // clear inString
      command.motor = 0;
      command.mspeed = 0;
      Serial.println("quit/stop received");
    }
  }
}

