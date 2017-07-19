#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;

int main() {
  cv::Mat img;
  cv::Mat dst;

  //cv::imshow("img", img);
  //cv::waitKey();

  cv::VideoCapture input("test.mp4");

  cv::VideoWriter output("testout.avi", CV_FOURCC('X','V', 'I', 'D'), 30, cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH), input.get(CV_CAP_PROP_FRAME_HEIGHT)));

  int num = 0;

  for(;;) {
    if (!input.read(img))
      break;
    cout<<"Frame number: "<<num<<endl;
    num++;
    cv::Sobel(img,dst, CV_8U, 1, 1);
    output.write(dst);

    cv::imshow("img", img);
    char c = cv::waitKey(1);
    if (c == ' ')
      break;
  }

}
