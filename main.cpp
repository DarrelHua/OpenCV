#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////// Basic Functions ///////////////////////

int main() {
    Mat img;
    img = imread("C:/Users/darre/Pictures/lenna.png");

    Mat imgGray;
    Mat imgBlur, imgCanny, imgDia, imgErode;
    if ( !img.data )
    {
        printf("No image data \n");
        return -1;
    }

    cvtColor(img,imgGray,COLOR_BGRA2GRAY);
    GaussianBlur(img,imgBlur,Size(9,9),5,0);
    Canny(imgBlur,imgCanny,25,75);

    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(imgCanny,imgDia,kernel);
    erode(imgDia,imgErode,kernel);

    imshow("Image",img);
    imshow("Image Gray", imgGray);
    imshow("Bluured Image",imgBlur);
    imshow("Canny Image", imgCanny);
    imshow("Dilated Image",imgDia);
    imshow("Dilated Image",imgErode);
    waitKey(0);
    return 0;
}


