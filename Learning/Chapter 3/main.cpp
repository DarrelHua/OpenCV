#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////// Resize and Crop ///////////////////////

int main() {
    Mat img, imgCrop;
    img = imread("C:/Users/darre/Pictures/lenna.png");

    if ( !img.data )
    {
        printf("No image data \n");
        return -1;
    }
    Mat imgResized;

    cout << img.size() << endl;
    resize(img,imgResized,Size(),0.5,0.5);

    Rect roi(100,100,300,250); //ROI: Region of Interest
    imgCrop = img(roi);

    imshow("Image",img);
    imshow("Resized",imgResized);
    imshow("Cropped",imgCrop);
    waitKey(0);
    return 0;
}


