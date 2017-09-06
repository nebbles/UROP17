//UROP17
//Maze detection and marble detection

#include <iostream>
#include <string>
#include <sstream>
#include "opencv/cv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/tracking.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

//We use HSV filter values to detect the maze
int H_MIN = 66;
int H_MAX = 155;
int S_MIN = 180;
int S_MAX = 256;
int V_MIN = 101;
int V_MAX = 199;
//We use HSV filter values to detect the marble
int H2_MIN = 137;
int H2_MAX = 180;
int S2_MIN = 59;
int S2_MAX = 251;
int V2_MIN = 68;
int V2_MAX = 180;


String intToString(int number){


  stringstream ss;
  ss << number;
  return ss.str();
}

void RemoveNoise(Mat &thresh){

  //create structuring element that will be used to "dilate" and "erode" image.
  //the element chosen here is a 3px by 3px rectangle

  Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
  //dilate with larger element so make sure object is nicely visible
  Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

  erode(thresh,thresh,erodeElement);
  erode(thresh,thresh,erodeElement);
  erode(thresh, thresh, erodeElement);
  erode(thresh, thresh, erodeElement);


  dilate(thresh,thresh,dilateElement);
  dilate(thresh,thresh,dilateElement);
  //dilate(thresh,thresh,dilateElement);



}

void trackFilteredObject(int &x, int &y, Mat threshold, Mat &cameraFeed){

  Mat temp;
  threshold.copyTo(temp);

  //these two vectors needed for output of findContours
  vector< vector<Point> > contours;
  vector<Vec4i> hierarchy;

  //find contours of filtered image using openCV findContours function
  findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );

  //use moments method to find our filtered object
  double refArea = 0;
  bool objectFound = false;
  if (hierarchy.size() > 0) {
    int numObjects = hierarchy.size();
    //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
    if(numObjects<10){
      for (int index = 0; index >= 0; index = hierarchy[index][0]) {

	Moments moment = moments((cv::Mat)contours[index]);
	double area = moment.m00;

	//if the area is less than 20 px by 20px then it is probably just noise
	//we only want the object with the largest area so we save a reference area each
	//iteration and compare it to the area in the next iteration.
	if(area>(20*20) && area<(300*300) && area>refArea){
	  x = moment.m10/area;
	  y = moment.m01/area;
	  objectFound = true;
	  refArea = area;
	}
	else {
	  objectFound = false;
	}
      }

      //let user know you found an object
      if(objectFound ==true){
	putText(cameraFeed,"Tracking Object",Point(0,50),2,1,Scalar(0,255,0),2);
	//draw object location on screen
	circle(cameraFeed,Point(x,y),20,Scalar(0,255,0),2);
	putText(cameraFeed,intToString(x)+","+intToString(y),Point(x,y+30),1,1,Scalar(0,255,0),2);
      }

    }
    else {
      putText(cameraFeed,"TOO MUCH NOISE: ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
    }
  }
}

int main(){

  //Create Mat objects to store images in
  Mat cameraFeed;
  Mat HSV;
  Mat threshold;
  Mat threshold_marble;

  //Store position co-ordinates of the object
  int x=0;
  int y=0;

  VideoCapture input("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)I420, "
		     "framerate=(fraction)120/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! "
		     "videoconvert ! video/x-raw, format=(string)BGR ! appsink");

  for(;;){

    //Store camera input into a matrix
    input >> cameraFeed;
    //Apply Gaussian Blur to reduce noise in image
    //GaussianBlur(cameraFeed, HSV, Size(11, 11), 4);
    //Convert camerafeed from BGR to HSV
    cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);
    //Filter HSV Values to detect the maze
    //Maze: H(48, 190) S(182, 256) V(53, 146)
    inRange(HSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);
    //Filter HSV Values to detect the marble
    inRange(HSV,Scalar(H2_MIN,S2_MIN,V2_MIN),Scalar(H2_MAX,S2_MAX,V2_MAX),threshold_marble);
    //Eliminate some noise by eroding into binary image, then dilating to restore
    //areas that were not removed from erosion
    RemoveNoise(threshold_marble);
    //Track the object detected in the thresholded image and obtain co-ordinates
    trackFilteredObject(x, y, threshold_marble, cameraFeed);
    imshow("Window", cameraFeed);

    threshold_marble += threshold;

    imshow("Window1", threshold_marble);

    if(waitKey(30)==27){
      break;
    }

  }
  return 0;
}
