#include <iostream>
#include "opencv/cv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

    Mat image = imread(argv[1],1);

    Mat Copy;
    image.copyTo(Copy);

    cvtColor(Copy, Copy, CV_BGR2GRAY);
    threshold(Copy, Copy, 50, 255, CV_THRESH_BINARY_INV);

    namedWindow("image", CV_WINDOW_FREERATIO);
    imshow("image", image);

    cout<<"Press any key to continue..."<<endl;
    waitKey(); // wait before displaying solution

    vector< vector<Point> > Contours;
    findContours(Copy, Contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    Mat draw;
    draw = Mat::zeros(image.size(), CV_32FC1);
    cout<<Contours.size();
    drawContours(draw, Contours, 0, Scalar(255), -1);
    namedWindow("image2", CV_WINDOW_FREERATIO);
    imshow("image2", draw);

    Mat dilated, eroded;
    Mat kernel = Mat::ones(21, 21, CV_8UC1);

    dilate(draw, dilated, kernel, Point(-1, -1), 2, BORDER_CONSTANT);
    namedWindow("dilate", CV_WINDOW_FREERATIO);
    imshow("dilate", dilated);

    erode(dilated, eroded, kernel, Point(-1, -1), 1, BORDER_CONSTANT);
    namedWindow("erode", CV_WINDOW_FREERATIO);
    imshow("erode", eroded);

    Mat diff;
    absdiff(dilated, eroded, diff);
    diff.convertTo(diff, CV_8UC1);
    namedWindow("diff", CV_WINDOW_FREERATIO);
    imshow("diff", diff);

    vector< vector<Point> > PathContours;
    findContours(diff, PathContours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
    Mat draw2;
    draw2 = Mat::zeros(image.size(), CV_32FC1);
    cout<<PathContours.size();
    drawContours(image, PathContours, 0, Scalar(0,255,0), -1);
    namedWindow("final", CV_WINDOW_FREERATIO);
    imshow("final", image);

    for(;;){
        cout<<"Press ESC to exit program"<<endl;
        if (waitKey()==27) break;
    }
}
