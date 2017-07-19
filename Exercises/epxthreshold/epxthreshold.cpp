#include <iostream>
#include "opencv/cv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

    Mat image = imread(argv[1], 1);

    Mat Copy;
    //double thresh = atof(argv[2]);
    //double maxValue = atof(argv[3]);

    //threshold(image, Copy, thresh, maxValue, THRESH_TOZERO);

    inRange(image, Scalar(0,50,0),Scalar(35,255,35),Copy);
    bitwise_not(Copy, Copy);

    namedWindow("Threshold", CV_WINDOW_NORMAL);
    resizeWindow("Threshold", 1280, 720);
    imshow("Threshold", Copy);

    if(waitKey()==27){ return 0;}
}
