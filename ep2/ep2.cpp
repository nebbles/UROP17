#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
  cv::Mat img = cv::imread("lena.png");

  cv:imshow("img", img);
  cv::waitKey();

}
