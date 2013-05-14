/* 
 * File:   main.cpp
 * Author: tholum
 *
 * Created on May 12, 2013, 9:01 PM
 */


#include <cstdlib>
#include <opencv/cv.h>
using namespace cv;

/*
 * 
 */
int main(int argc, char** argv) {
    CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
    while(1){
        IplImage* frame = cvQueryFrame( capture );
        imwrite( "/var/www/image.jpg", frame );
        
    }
    return 0;
}

