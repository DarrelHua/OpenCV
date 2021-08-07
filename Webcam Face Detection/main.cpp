#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <time.h>

//xml files have our trained models
using namespace cv;
using namespace std;

/////////////////////// Face Detection Webcam///////////////////////
int main() {

    VideoCapture cap(0); //If only one camera, camera ID 0 is fine
    Mat img;

    CascadeClassifier faceCascade;
    faceCascade.load("C:/Users/darre/Downloads/Resources/Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty()) {
        cout << "XML not found" << endl;
        return -1;
    }
    time_t startTime;
    time_t curTime;
    time(&startTime);
    int numFramesCaptured = 0;
    double secElapsed;
    double curFPS;

    while(true) {
        cap.read(img);
        if (!img.data) {
            cout << "No image data" << endl;
            break;
        }
        vector<Rect> faces;
        faceCascade.detectMultiScale(img,faces,1.1,10);
        //double fps = cap.get(CAP_PROP_FPS);
        for(int i = 0;i<faces.size();i++) {
            rectangle(img,faces[i].tl(),faces[i].br(),Scalar(255,0,255),3);
        }
        //cout << "FPS: " << fps << endl;
        imshow("Display Image", img);
        numFramesCaptured++;
        time(&curTime);
        double secElapsed = difftime(curTime,startTime);
        double curFPS = numFramesCaptured/secElapsed;
        cout << "FPS: " << curFPS << endl;
        waitKey(1);
    }
    cap.release();
    return 0;
}



