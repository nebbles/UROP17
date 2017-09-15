// getSerial() deciphers string command sent over USB Serial.
// It is called for each time there is a character available
// in the Serial buffer.
//

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
  }
  else {
    inString += inChar;
    
    if (inString == "a") {
      inString = ""; // clear inString
      stopA();
      Serial.println("Stopping motor A");
    }

    if (inString == "b") {
      inString = ""; // clear inString
      stopB();
      Serial.println("Stopping motor B");
    }
    
    if (inString == "quit" || inString == "q" || inString == "stop") {
      inString = ""; // clear inString
      stopAll();
      Serial.println("quit/q/stop received");
    }   
  }
}

