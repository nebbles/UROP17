void setup()
{
    Serial.begin(9600);
    while(!Serial){;}
    Serial.println("Serial connected");
}
int input,num;
int buff[5];
int j=-1;

int calc()
{
    int num=0;

    for(int x=0;x<=j;x++)
          num=num+(buff[x]-48)*pow(10,j-x);

    return num;
}

void loop()
{
    if(Serial.available()>0)
    {
        input=Serial.read();

        if(input==',')
        {
            num=calc();
            j=-1;
            Serial.println(num);
            Serial.println("Subtracting 5");
            num = num-5
            Serial.println(num);
        }
        
        else
        {
            j++;
            buff[j]=input;
        }
    }
}


