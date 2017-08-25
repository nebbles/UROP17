// arduino_com_mac.cpp
// 25 August 2017
//
// On Macintosh, compiled program must be run with 'sudo'

#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
    string portName;
    cout << "Default port name for Mac: /dev/cu.usbmodem1421" << endl;
    cout << "Type 'mac' to use Mac default:" << endl;
    cout << "Input port name: ";
    cin >> portName; // save user input to portName
    
    if (portName == "mac") {
        portName = "/dev/cu.usbmodem1421";
        cout << "Using default Mac port" << endl;
    }
    if (portName == "tx") {
        portName = "/dev/ttyACM0";
        cout << "Using default TX2 port" << endl;
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
        
    } while(data != "quit");
    
    fclose(file);
}
