#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace cv;

int main(){
    cv::VideoCapture input("test.mp4");
    Mat img, img_prev;
    vector<Point2f> points, points_prev;
    vector<uchar> status;
    vector<float> error;

    Ptr<ORB> detector = ORB::create();
    vector<KeyPoint> keypoints;

    input.read(img);
    detector->detect(img, keypoints, Mat());
    KeyPoint::convert(keypoints, points);
    img.copyTo(img_prev);
    points_prev = points;

    for(;;){
        if(!input.read(img))
            break;

        //detector->detect(img, keypoints, Mat());
        calcOpticalFlowPyrLK(img_prev, img, points_prev, points, status, error);

        img.copyTo(img_prev);
        points_prev = points;

//        for (size_t i = 0; i< keypoints.size(); i++)
        for (size_t i = 0; i< points.size(); i++)

            circle(img, points[i], 2, Scalar(0,0,255), 1);
        imshow("img", img);
        char c = waitKey(1);
        waitKey(1);
        if(c==27)
            break;
    }

}
