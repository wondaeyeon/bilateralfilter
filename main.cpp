// Basic Bilateral Filter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "BilateralFilter.h"

void displayImage(char * winName,IplImage* image){
	cvNamedWindow(winName,0);
	cvShowImage(winName,image);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* filename = ".\\images\\cat.png";
	IplImage * oimage = cvLoadImage(filename);

	displayImage("original", oimage);

	double spacestdv = 10;
	double rangestdv = 6;
	BilateralFilter * bilateral = new BilateralFilter(oimage,spacestdv,rangestdv);
	IplImage * bilateralImage = bilateral->runFilter();

	displayImage("bilateral",bilateralImage);
	
	cvWaitKey(0); 
	return 0;
}

