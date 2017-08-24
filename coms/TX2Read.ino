
void setup()
{
    Serial.begin(9600);
    Serial.println("Working");
}
char input,num;
int temp;
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
        String instring;
        instring += input;
        temp = instring.toInt();
        Serial.println(temp);

        //Serial.println(input);
        if(temp==1){
        Serial.println("Received 1");
        }

//        if(input==',')
//        {
//            num=calc();
//            j=-1;
//            Serial.println(num);
//        }
//        
//        else
//        {
//            j++;
//            buff[j]=input;
//        }
    }
    
}


