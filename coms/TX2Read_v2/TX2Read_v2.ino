
void setup()
{
  Serial.begin(9600);
  Serial.println("TX2Read v2");
  Serial.println(" ");
}
char inChar;
String inString;
int number;

void loop()
{
  if (Serial.available() > 0)
  {
    inChar = Serial.read();
    Serial.print("Char received: ");
    Serial.println(inChar);

    if (inChar == ',') { // comma found to convert to int
      number = inString.toInt();
      inString = "";
      Serial.print("The number, as Int: ");
      Serial.println(number);

      if (number == 1) {
        Serial.println("Received 1 (as an Int!)");
      }
      if (number > 5) {
        Serial.println("Number is greater than 5!");
      }
      Serial.print("The number with +1: ");
      Serial.println(number + 1);
      Serial.println(""); // spread out Serial prints

    }
    else if (inChar == '.') {
      // TODO
      // end of command
      // execute the command
      Serial.println("Command would end here and would act on it.");
    }
    else {
      inString += inChar;
      Serial.print("String updated to: ");
      Serial.println(inString);
      if (inString == "quit") {
        inString = ""; // set inString back to blank after hearing quit command
      }
    }
  }

}


