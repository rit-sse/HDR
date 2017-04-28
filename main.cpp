#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/photo.hpp>
#include "opencv2/imgcodecs.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  // INPUT PARSE
  double gamma = 1.9f;
  double saturation = 1.9f;
  double bias = 1.9f;

  // MAIN
  Mat xyz, Y, lumOut;
  Mat input = imread(argv[1]);

  // Create the tone map for the tv
  Mat ldr;
  Ptr<TonemapDrago> tonemap = createTonemapDrago(gamma, saturation, bias);
  tonemap->process(input, ldr);

  // get the Y channel for the projector
  cvtColor(input, xyz, CV_BGR2XYZ);
  vector<Mat> channels(3);
  // split img:
  split(xyz, channels);
  channels[0] = channels[1];
  channels[2] = channels[1];

  merge(channels, Y);

  // Display
  imshow("front", ldr);
  imshow("projector", Y);

  waitKey();
  return 0;
}
