#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int data[] = {12,23,32};  //Random data we want to send
    FILE *file;
    file = fopen("/dev/ttyACM0","w");  //Opening device file
    
    
    for(int i = 0 ; i < 3 ; i++)
    {
        fprintf(file,"%d",data[i]); //Writing to the file
        fprintf(file,"%c",','); //To separate digits
        //sleep(1);
    }
    fclose(file);
}
