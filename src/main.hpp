#ifndef __TRACKFULLBODY_H__
#define __TRACKFULLBODY_H__

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char** argv );

void detectAndDisplay(cv::Mat frame, cv::String window_name, cv::CascadeClassifier cascade);

#endif
