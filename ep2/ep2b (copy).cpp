#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
  cv::Mat img = cv::imread("lena.png");

  cv::imshow("img", img);
  cv::waitKey();

  cv::VideoCapture input(0);

  while(true) {
    if (!input.read(img))
      break;

    cv::imshow("img",img);
    char c = cv::waitKey(30);
    if (c == ' ')
      break;
  }

}
