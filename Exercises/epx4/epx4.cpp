#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

    cout<<"Options: \n"
          "1. Video input : Type name of file. \n"
          "2. Camera : Press Enter."
       <<endl;



    //set input type

    string video;
    getline(cin, video);

    if(video==""){
       video = "nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080,format=(string)I420, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
    }


  // declares all required variables

  Rect2d roi;
  Mat frame;

  // create a tracker object

  Ptr<Tracker> tracker = TrackerKCF::create();


  //set input video

  VideoCapture cap(video);


  // get bounding box

  cap >> frame;
  roi=selectROI("tracker",frame);


  //quit if ROI was not selected
  if(roi.width==0 || roi.height==0)
    return 0;

  // initialize the tracker

  tracker->init(frame,roi);

  // perform the tracking process
  printf("Start the tracking process, press ESC to quit.\n");

  for ( ;; ){
    // get frame from the video
    cap >> frame;

    // stop the program if no more images
    if(frame.rows==0 || frame.cols==0)
      break;

    // update the tracking result

    tracker->update(frame,roi);

    // draw the tracked object
    rectangle( frame, roi, Scalar( 255, 0, 0 ), 2, 1);

    // show image with the tracked object
    imshow("tracker",frame);

    //quit on ESC button
    if(waitKey(5)==27) break;
  }

  return 0;
}
