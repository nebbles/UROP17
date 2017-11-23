unsigned long serialdata;
int inbyte;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  getSerial();
  Serial.println("Completed getSerial");
}

long getSerial() 
{
  Serial.println("Running func");
  serialdata = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read();  
    if (inbyte > 0 && inbyte != '/')
    { 
      serialdata = serialdata * 10 + inbyte - '0';
      Serial.println(serialdata);
    }
  }
  inbyte = 0;
  Serial.print("OUTPUT: ");
  Serial.println(serialdata);
  return serialdata;
}
