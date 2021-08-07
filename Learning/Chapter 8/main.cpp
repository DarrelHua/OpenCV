#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

//xml files have our trained models
using namespace cv;
using namespace std;

/////////////////////// Face Detection Images ///////////////////////
int main() {
    Mat img,img2;
    img = imread("C:/Users/darre/Downloads/Resources/Resources/test.png");
    img2 = imread("C:/Users/darre/Pictures/lenna.png");
    if ( !img.data )
    {
        printf("No image data \n");
        return -1;
    }

    CascadeClassifier faceCascade;
    faceCascade.load("C:/Users/darre/Downloads/Resources/Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty()) {
        cout << "XML not found" << endl;
        return -1;
    }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img,faces,1.1,10);
    vector<Rect> faces2;
    faceCascade.detectMultiScale(img2,faces2,1.1,10);

    for(int i = 0;i<faces.size();i++) {
        rectangle(img,faces[i].tl(),faces[i].br(),Scalar(255,0,255),3);
    }
    for(int i = 0;i<faces2.size();i++) {
        rectangle(img2,faces2[i].tl(),faces2[i].br(),Scalar(255,0,255),3);
    }

    imshow("Display Image", img);
    imshow("Display Image 2", img2);
    waitKey(0);
    return 0;
}


