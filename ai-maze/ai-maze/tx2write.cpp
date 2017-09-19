//
// AI-Maze
// Created by Shreyus Bagga and Benedict Greenberg
// September 2017
//
// tx2write.cpp
//
// Version 2.0
// Author: B.S.D.Greenberg
// Created: 29 August 2017
// Last modified: 19 September 2017
//
// On Macintosh, compiled program must be run with 'sudo'
// All other instructions are within program. Run from the terminal.
//
// Program is designed to work with the latest version of TX2Read running on an Arduino Uno.
//

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> // abs()

using namespace std;

class PIDC {
public:
    
    int Kp;
    int Kd;
    int Ki;
    
    int baseTarget; // this should be theta_0
    int target; // this should be theta_0
    int limit = 2; // limit the tilt (motor position) from zero position
    int integrator = 0;
    
    PIDC(int Kp_in = 0, int Kd_in = 0, int Ki_in = 0, int theta_0_in = 0){ // constructor
        Kp = Kp_in;
        Kd = Kd_in;
        Ki = Ki_in;
        
        baseTarget = theta_0_in;
        target = theta_0_in;
    };
    
    void updateDerivative(){
        // update the derivative term of the ball
    }
    
    void targetSet(int value){
        if ( abs(value) <= limit ) {
            target = baseTarget + value;
            integrator = 0;
            Kp = 1;
        }
    }
    
    void targetReset() {
        target = baseTarget;
        integrator = 0;
    }
    
    int getTilt(int pitch, int pitch_dot) {
        int pError = pitch - target; // calculate error from target
        
        int output = Kp * pError + Kd * pitch_dot + Ki * integrator;
        
        integrator += pError;
        
        // limit output to + - 100 PWM value
        if (output > 100) {
            output = 100;
        }
        else if (output < -100) {
            output = -100;
        }
        
        return output;
    }
    
    
};

int main()
{
    string portName;
    
    cout << "TX2Write Version 2.0" << endl;
    
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

int getPID(int errorValue) {
    // TODO; get the Error value
    // TODO; pass into P using coeff
    // TODO; pass into I using class
    // TODO; pass into D using coeff
    
    return 0;
}

int sendCommand() {
    // TODO; take desired command
    // TODO; check command falls within allowed limits
    // TODO; limit command if not allowed
    return 0;
}

