#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  Mat xyz, _y_;
  Mat input = imread("apartment.hdr");

  cvtColor(input, xyz, CV_BGR2XYZ);
  extractChannel(xyz, _y_, 1);

  for_each(_y_.begin<uchar>(), _y_.end<uchar>(), [](uchar& pixel) {
      // pixel = (uchar) sqrt(pixel);
    });

  imshow("front", input);
  imshow("projector", _y_);

  waitKey();
  return 0;
}
