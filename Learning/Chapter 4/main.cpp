#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////// Draw Shapes and Text ///////////////////////

int main() {
    
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));

    circle(img,Point(256,256),155,Scalar(0,0,0),FILLED);
    rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,150),FILLED);
    line(img,Point(130,296),Point(382,296),Scalar(123,123,231),2);

    putText(img,"Darrels OpenCV Advenventure",Point(137,262),FONT_HERSHEY_TRIPLEX,0.3,Scalar(0,255,150),1);

    imshow("Image",img);
    waitKey(0);
    return 0;
}


