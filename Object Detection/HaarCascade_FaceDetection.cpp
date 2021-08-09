#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <time.h>

//xml files have our trained models
using namespace cv;
using namespace std;

// This current implementation provides around 4.5 FPS, looking to improve this through optimization techniques and CUDA
//CascadeClassifier face_cascade;
///////////////////// Face Detection Webcam///////////////////////
CascadeClassifier faceCascade;
void faceDetection(Mat img) {
    vector<Rect> faces;
    Mat grey_img;

    cvtColor(img,grey_img,COLOR_BGR2GRAY);
    faceCascade.detectMultiScale(img,faces,1.1,10);
    
    for(int i = 0;i<faces.size();i++) {
        rectangle(img,faces[i].tl(),faces[i].br(),Scalar(255,0,255),3);
    }
    imshow("Greyscale Detection",grey_img);
}
int main() {

    VideoCapture cap(0); //If only one camera, camera ID 0 is fine
    Mat img;

    
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
    Mat resized;
    while(cap.read(img)) {
        
        if (img.empty()) {
            cout << "No image data" << endl;
            break;
        }
        vector<Rect> faces;
        //resize(img,resized,Size(640,480));
        Mat grey_img;

        cvtColor(img,grey_img,COLOR_BGR2GRAY);
        faceCascade.detectMultiScale(grey_img,faces,1.1,10); //Detection on gray scale is less intensive computationally
    
        

        numFramesCaptured++;
        time(&curTime);
        double secElapsed = difftime(curTime,startTime);
        double curFPS = numFramesCaptured/secElapsed;
        //cout << "FPS: " << curFPS << endl;
        for(int i = 0;i<faces.size();i++) {
            rectangle(img,faces[i].tl(),faces[i].br(),Scalar(255,0,255),3);
            putText(img,"FPS: " + to_string(curFPS),Point(faces[i].x,faces[i].y-10),FONT_HERSHEY_PLAIN,0.7,Scalar(255,0,0),1);
        }
        imshow("Detector",img);
        if (waitKey(10) == 'q')
        {
            break; // Terminate program if q pressed
        }
    }
    cap.release();
    return 0;
}



// int main() {

//     VideoCapture cap(0); //If only one camera, camera ID 0 is fine
//     Mat img;

//     while(true) {
//         cap.read(img);
//         if (!img.data) {
//             break;
//         }
//         namedWindow("Display Image", WINDOW_AUTOSIZE );
//         imshow("Display Image", img);
//         waitKey(1);
//     }
//     return 0;
// }



