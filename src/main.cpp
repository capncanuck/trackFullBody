#include "main.hpp"

/** @function main */
int main(int argc, char** argv) {
    cv::Mat frame;
    cv::String fullbody_cascade_name = argv[1];
    cv::CascadeClassifier fullbody_cascade;

    //-- 1. Load the cascades
    if (!fullbody_cascade.load(fullbody_cascade_name)) {
        printf("--(!)Error loading full body cascade\n");
        return -1;
    };

    //cv::VideoCapture capture("http://192.168.2.12:8080/videofeed?.mjpg");
    //cv::VideoCapture capture(1);
    cv::VideoCapture capture("http://localhost:8080/videofeed?.mjpg");
    //cv::VideoCapture capture(0);

    //-- 2. Read the video stream
    if (!capture.isOpened()) {
        printf("--(!)Error opening video capture\n");
        return -1;
    }

    while (capture.read(frame)) {
        if (frame.empty()) {
            printf(" --(!) No captured frame -- Break!");
            break;
        }

        //-- 3. Apply the classifier to the frame
        detectAndDisplay(frame, fullbody_cascade_name, fullbody_cascade);

        if ((char) cv::waitKey(10) == 27) {
            break;
        } // escape
    }
    return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(cv::Mat frame, cv::String window_name, cv::CascadeClassifier cascade) {
    std::vector<cv::Rect> faces;

    //-- Detect faces
    cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    /*for (size_t i = 0; i < faces.size(); i++) {
     //cv::Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
     //cv::circle(frame, center, faces[i].width / 2, cv::Scalar(255, 0, 255));
     cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 255));
     }*/

    if (faces.size() > 0) {
        cv::rectangle(frame, faces[0], cv::Scalar(255, 0, 255));
    }
    //-- Show what you got
    imshow(window_name, frame);
}
