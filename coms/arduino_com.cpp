#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
    //int data[];  //Random data we want to send
	string data;
    FILE *file;
    file = fopen("/dev/ttyACM1","w");  //Opening device file
    
    
    do
    {
	cin>>data;
        fprintf(file,"%s",data.c_str()); //Writing to the file
        //fprintf(file,"%c",','); //To separate digits
	fflush(file);
        //sleep(1);
    }while(data!="end");
    fclose(file);
}
