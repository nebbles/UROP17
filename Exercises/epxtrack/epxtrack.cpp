#include <iostream>
#include "opencv/cv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/tracking.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;

const int FRAME_WIDTH = 1280;
const int FRAME_HEIGHT = 720;

//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string windowName3 = "After Morphological Operations";
const string trackbarWindowName = "Trackbars";
void on_trackbar( int, void* )
{//This function gets called whenever a
    // trackbar position is changed
}
string intToString(int number){

    std::stringstream ss;
    ss << number;
    return ss.str();
}
void createTrackbars(){
    //create window for trackbars
    namedWindow(trackbarWindowName,0);
    //create memory to store trackbar name on window
    char TrackbarName[50];
    sprintf( TrackbarName, "H_MIN", H_MIN);
    sprintf( TrackbarName, "H_MAX", H_MAX);
    sprintf( TrackbarName, "S_MIN", S_MIN);
    sprintf( TrackbarName, "S_MAX", S_MAX);
    sprintf( TrackbarName, "V_MIN", V_MIN);
    sprintf( TrackbarName, "V_MAX", V_MAX);
    //create trackbars and insert them into window
    //3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
    //the max value the trackbar can move (eg. H_HIGH),
    //and the function that is called whenever the trackbar is moved(eg. on_trackbar)
    //                                  ---->    ---->     ---->
    createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
    createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
    createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
    createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
    createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
}


void morphOps(Mat &thresh){

    //create structuring element that will be used to "dilate" and "erode" image.
    //the element chosen here is a 3px by 3px rectangle

    Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
    //dilate with larger element so make sure object is nicely visible
    Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

    erode(thresh,thresh,erodeElement);
    erode(thresh,thresh,erodeElement);


    dilate(thresh,thresh,dilateElement);
    dilate(thresh,thresh,dilateElement);


}

int main(int argc, char* argv[])
{
    //some boolean variables for different functionality within this program
    bool trackObjects = false;
    bool useMorphOps = true;

    //matrix to store image
    VideoCapture input("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)I420, framerate=(fraction)120/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");
    Mat cameraFeed; /* = imread("maze5-rb.png"); */

    //matrix storage for HSV image
    Mat HSV;
    //matrix storage for binary threshold image
    Mat threshold;
    //x and y values for the location of the object
    int x=0, y=0;

    Rect2d roi;

    // create a tracker object

    Ptr<Tracker> tracker = TrackerKCF::create();

    input >> cameraFeed;
    roi=selectROI("tracker",cameraFeed);

    if(roi.width==0 || roi.height ==0) return 0;

    tracker->init(cameraFeed, roi);

    while(1){

        input >> cameraFeed;

        if(cameraFeed.rows ==0 || cameraFeed.cols==0) break;

        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
        //filter HSV image between values and store filtered image to
        //threshold matrix
        createTrackbars();
        //        H_MIN = 0; H_MAX = 180; S_MIN = 180;
        //        S_MAX = 256; V_MIN = 62; V_MAX = 188;
        inRange(HSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);
        //perform morphological operations on thresholded image to eliminate noise
        //and emphasize the filtered object(s)
        if(useMorphOps){
            morphOps(threshold);
        }

        tracker->update(cameraFeed, roi);

        rectangle(cameraFeed, roi, Scalar(255, 0, 0), 2, 1);

        cvtColor(threshold, threshold, COLOR_GRAY2BGR);
        rectangle(threshold, roi, Scalar(255, 0, 0), 2, 1);
        rectangle(HSV, roi, Scalar(0, 255, 0), 2, 1);

        //pass in thresholded frame to our object tracking function
        //this function will return the x and y coordinates of the
        //filtered object


        //        if(trackObjects)
        //            trackFilteredObject(x,y,threshold,cameraFeed);




        //show frames
        namedWindow(windowName2, WINDOW_NORMAL);
        resizeWindow(windowName2, 640, 480);
        imshow(windowName2,threshold);
        //        namedWindow(windowName, WINDOW_NORMAL);
        //        resizeWindow(windowName, 640, 480);
        //        imshow(windowName,cameraFeed);
        namedWindow(windowName1, WINDOW_NORMAL);
        resizeWindow(windowName1, 640, 480);
        imshow(windowName1,HSV);


        //delay 30ms so that screen can refresh.
        //image will not appear without this waitKey() command

        if(waitKey(30)==27) break;


    }
}
