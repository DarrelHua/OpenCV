#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////// Shape/Contour Detection ///////////////////////

Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    //drawContours(img,contours,-1,Scalar(255,0,255),2);

    vector<vector<Point>> contPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    string objType;

    //From this we can see that there is an area that is very small, allowing us to find and eliminate noise
    for (int i =0; i < contours.size(); i++ ) {
        double area = contourArea(contours[i]);
        cout << area << endl;
        if (area > 1000) {
            float perim = arcLength(contours[i],true);
            approxPolyDP(contours[i],contPoly[i],0.02*perim,true);
            //drawContours(img,contPoly,i,Scalar(255,0,255),2); //Eliminated small circle and mapped out perimeters of shapes to try and start classifying based on # of corners
            cout << contPoly[i].size() << endl; //Prints # of corners per shape
            boundRect[i] = boundingRect(contPoly[i]); //Built a boudning box around our shapes
            //rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,150),5); //Created a rectangle per shape to be bounded and writing to img

            int objCor = (int)contPoly[i].size();

            if(objCor == 3) {
                objType = "Triangle";
            }
            if(objCor == 4) {
                float aspRatio = (float)boundRect[i].width/(float)boundRect[i].height;
                if (aspRatio > 0.95 && aspRatio < 1.05)
                    objType = "Square";
                else
                    objType = "Rectangle";
            }
            if(objCor > 4) {
                objType = "Circle";
            }

            drawContours(img,contPoly,i,Scalar(255,0,255),2); //Eliminated small circle and mapped out perimeters of shapes to try and start classifying based on # of corners
            putText(img,objType,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_TRIPLEX,0.7,Scalar(0,0,0),1);
            rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,150),5); //Created a rectangle per shape to be bounded and writing to img
            
            
        }
    }
}

int main() {
    
    string path = "C:/Users/darre/Downloads/Resources//Resources/shapes.png";
    Mat img  =imread(path);

    //Preprocessing of the image
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny, imgDil,kernel); //Dialted image provides easier detection of shapes

    getContours(imgDil,img);

    imshow("Image",img);
    // imshow("Image Gray",imgGray);
    // imshow("Image Blur",imgBlur);
    // imshow("Image Canny",imgCanny);
    // imshow("Image Dil",imgDil);
    waitKey(0);
    
    return 0;
}


