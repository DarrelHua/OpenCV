#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////// Images ///////////////////////
// int main() {
//     Mat img;
//     img = imread("C:/Users/darre/Pictures/lenna.png");
//     if ( !img.data )
//     {
//         printf("No image data \n");
//         return -1;
//     }
//     namedWindow("Display Image", WINDOW_AUTOSIZE );
//     imshow("Display Image", img);
//     waitKey(0);
//     return 0;
// }

/////////////////////// Video ///////////////////////
// int main() {

//     string path = "C:/Users/darre/Downloads/Resources//Resources/test_video.mp4";
//     VideoCapture cap(path);
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

/////////////////////// Webcam ///////////////////////
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
