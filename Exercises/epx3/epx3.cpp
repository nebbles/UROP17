#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/objdetect.hpp"
#include <stdio.h>
#include "opencv2/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    cv::VideoCapture input("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080,format=(string)I420, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");
    Mat img, img_gray;


    Ptr<ORB> orb = ORB::create(5);
    vector<KeyPoint> img_keypoints, obj_keypoints;
    Mat img_descriptors, obj_descriptors;

    input.read(img);
    Mat object2detect;
    img(Rect(900,600,400,400)).copyTo(object2detect);

    orb->detectAndCompute(object2detect, Mat(), obj_keypoints, obj_descriptors); //INVESTIGATE!!!!!!!!!!
    drawKeypoints(object2detect, obj_keypoints, object2detect);

    for(;;){
        if(!input.read(img))
            break;

        orb->detectAndCompute(img, Mat(), img_keypoints, img_descriptors);  //INVESTIGATE!!!!!!!!!!!!!!
        drawKeypoints(img, img_keypoints, img);

        BFMatcher matcher;
        vector<DMatch> matches;  //THIS IS THE ISSUE, matches.size() == 0. WHY?
        matcher.match(img_descriptors, obj_descriptors, matches);



        vector<Point2f> obj_points, img_points;

        for (int i = 0; i< matches.size(); i++)
        {
            obj_points.push_back(obj_keypoints[matches[i].queryIdx].pt);
            img_points.push_back(img_keypoints[matches[i].trainIdx].pt);
        }

        Matx33f H = findHomography(obj_points, img_points, RANSAC);

        vector<Point> obj_border, img_border;
        obj_border.push_back(Point(0,0));
        obj_border.push_back(Point(0,object2detect.rows));
        obj_border.push_back(Point(object2detect.cols,object2detect.rows));
        obj_border.push_back(Point(object2detect.cols, 0));

        Mat img_matches;

        drawMatches(img, img_keypoints, object2detect, obj_keypoints, matches, img_matches);


        for(size_t i = 0; i< obj_border.size(); i++){
            Vec3f p = H * cv::Vec3f(obj_border[i].x, obj_border[i].y, 1);
            img_border.push_back(Point(p[0]/p[2], p[1]/p[2]));
        }

        polylines(img,img_border, true, Scalar(0,255,0));



        imshow("img_matches", img_matches);
        char c = waitKey();
        waitKey(1);
        if(c==27)
            break;
    }

}
