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

#include "tx2write.hpp"

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> // abs()
#include <cstdio>   // clock
#include <ctime>    // clock

using namespace std;

void test() {
    cout << "Running test function from tx2write.cpp" << endl;
}

class PIDC {
public:
    int Kp;
    int Kd;
    int Ki;
    
    int positionCurrent = 0;
    int positionLast = 0;
    
    clock_t startTime;  // start clock
    double duration;    // save durations
    
    int target;         // this should start at basic target
    int limit = 10000;  // max limit for motor position in either direction
    int integrator = 0;
    
    PIDC(int P = 0, int I = 0, int D = 0){
        Kp = P;
        Ki = I;
        Kd = D;
        target = positionCurrent; // set initial target to current position
        startTime = std::clock(); // get initial time
    }; // Class constructor
    
    double getDuration(){
        duration = ( std::clock() - startTime ) / (double) CLOCKS_PER_SEC;
        
        startTime = std::clock();               // update time start point
        cout << "printf: " << duration << '\n'; // print duration
        
        return duration;
    } // gets time duration since last call
    
    int getDerivative(){
        int deltaPos = positionCurrent - positionLast;  // change in distance
        int deltaTime = 1;                              // change in time (TODO)
        int positionDerivative = deltaPos / deltaTime;  // calculate derivative term
        return positionDerivative;                      // return derivative term
    } // update the derivative term of the ball
    
    void reset() {
        target = positionCurrent;
        integrator = 0;
    } // stop and level the maze to current position
    
    void setTarget(int value){
        if ( abs(value) <= limit ) { // if value for ball position is within limit then
            target = value; // set target on axis as input value
            integrator = 0; // reset the integrator
        }
    } //TODO
    
    int getTilt(int position) {
        positionCurrent = position;                 // save current position
        int positionDerivative = getDerivative();   // get derivative using last known position
        positionLast = positionCurrent;             // update last position
        
        int pError = position - target;             // calculate error from target
        
        int output = Kp * pError + Kd * positionDerivative + Ki * integrator;
        
        integrator += pError;
        
        // limit output to + - 100 PWM value
        if (output > 100) { //TODO
            output = 100;
        }
        else if (output < -100) {
            output = -100;
        }
        
        return output;
    } // gets the desired output for motor using PID to get to current target
    
};

int tx2write()
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
    return 0;
}

int sendCommand() { // TODO
    // TODO; take x and y position
    // check validity and safety, limit if necessary
    // convert to corrrect format
    // send command
    return 0;
}

int start() { // TODO
    
    // set up PID controllers
    // arguments: P,I,D
    PIDC PIDCx(0,0,0);
    PIDC PIDCy(0,0,0);
    
    // calibrate
    
    // run ramp procedure
    
    
    // loop until quit
    
    int xpos = 0; // update x position
    int ypos = 0; // update y position
    
    PIDCx.getTilt(xpos);
    PIDCy.getTilt(ypos);
    
    sendCommand(); // send command to motors
    
    return 0;
}

