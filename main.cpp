#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/photo.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  Mat xyz, _y_, front, x, y, z;
  Mat input = imread("../apartment.hdr");

  cvtColor(input, xyz, CV_BGR2XYZ);
  extractChannel(xyz, _y_, 1);
  extractChannel(xyz, x, 0);
  extractChannel(xyz, y, 1);
  extractChannel(xyz, z, 2);

  for_each(y.begin<uchar>(), y.end<uchar>(), [](uchar& pixel) {
      pixel = sqrt((int) pixel);
    });

  std::vector<cv::Mat> array_to_merge;

  array_to_merge.push_back(x);
  array_to_merge.push_back(y);
  array_to_merge.push_back(x);

  merge(array_to_merge, front);

  cvtColor(front, input, CV_XYZ2RGB);

  imshow("front", input);
  imshow("projector", _y_);

  waitKey();
  return 0;
}
