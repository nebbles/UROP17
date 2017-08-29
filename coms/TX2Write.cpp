// TX2Write
// Version 1.0
// 29 August 2017
//
// On Macintosh, compiled program must be run with 'sudo'
// All other instructions are within program.
//
// Program is designed to work with the latest version of TX2Read running on an Arduino Uno.

#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
    string portName;
    cout << "Default ports: " << endl;
    cout << "mac : /dev/cu.usbmodem1421" << endl;
    cout << "tx  : /dev/ttyACM0" << endl << endl;
    cout << "Input port name: ";
    cin >> portName; // save user input to portName
    
    if (portName == "mac") {
        portName = "/dev/cu.usbmodem1421";
        cout << "Using default mac port" << endl;
    }
    else if (portName == "tx") {
        portName = "/dev/ttyACM0";
        cout << "Using default tx port" << endl;
    }
    cout << "PORT NAME: " << portName << endl;
    cout << "Type 'quit' to exit the program." << endl << endl;

    string data; // data string to be sent over USB Serial
    FILE *file; // file object for port used
    file = fopen(portName.c_str(),"w");  // opening device file
    
    do {
    cout << ">> ";
	cin >> data;
    fprintf(file,"%s",data.c_str()); //Writing to the file
    //fprintf(file,"%c",','); //To separate numbers
	fflush(file);
        
    } while(data != "quit" && data != "q");
    
    fclose(file);
}
