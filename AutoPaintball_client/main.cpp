#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
//	VideoCapture capture(-1); // use webcam
    //VideoCapture capture("input.mpg"); // use input file
    Mat frame;
    Mat image;
//	while(true) {
  //              capture >> frame;
	frame = imread( "/var/www/img/test.jpg", 1 );
				//IplImage* frame_ipli=cvCloneImage(&(IplImage)frame);
				IplImage* frame_ipli = &frame.operator IplImage()
				IplImage* channelRed = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				IplImage* channelGreen = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				IplImage* channelBlue = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				IplImage* filter1 = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				IplImage* filter2 = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				IplImage* cleani = cvCreateImage(cvGetSize(frame_ipli), 8, 1);
				
				cvInRangeS(frame_ipli, cvScalar(109, 206, 146 ), cvScalar(119, 218, 156), filter1 );
				cvInRangeS(frame_ipli, cvScalar(92, 196, 133 ), cvScalar(102, 206, 143 ),filter2 );
				cvAdd( filter1 , filter2 , cleani );				
				cvInRangeS(frame_ipli, cvScalar(79, 156, 112 ), cvScalar(89, 166, 122 ),filter1 );
				cvAdd(cleani,filter1,cleani);
				cvInRangeS(frame_ipli, cvScalar(130, 235, 186 ), cvScalar(140, 245, 286 ),filter1 );
                                cvAdd(cleani,filter1,cleani);
				cvInRangeS(frame_ipli, cvScalar(103, 197, 142 ), cvScalar(113, 207, 242 ),filter1 );
                                cvAdd(cleani,filter1,cleani);
                		Mat green=cvarrToMat(channelGreen);
				Mat blue=cvarrToMat(channelBlue);
				Mat clean=cvarrToMat(cleani);
				blur(clean,clean,Size(3,3) );
				cvInRange(clean,cvScalar(100,100,100),cvScalar(255,255,255),clean);
			//	Mat clean=cvarrToMat(filter1);
			imwrite( "/var/www/img/test2.jpg", clean );
			//imwrite("/var/www/img/frame.jpg", frame );
  //          }
}
