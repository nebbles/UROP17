#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

int main() {
    Mat image;

    VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)I420, framerate=(fraction)24/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");

    for (;;) {
        cap >> image;

        if(!image.empty()){
            imshow("window1", image);
        }

        // delay 33ms and break on ESC key

        if(waitKey(33)==27){
            break;
        }
    }
}
