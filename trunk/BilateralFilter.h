#include "cv.h"
#include "cxcore.h"

class BilateralFilter{
public:
	IplImage * image;
	IplImage * rimage ;
	IplImage * edimage;
	double kernelRadius;
	double ** kernelD;
	double *gaussSimilarity;
	int contrastParameter;
	bool mouseInteraction;
	int strokeWidth;
	BilateralFilter(IplImage *image,double sigmaD, double sigmaR);
	
	IplImage * runFilter();
	void apply(int i,int j);
	void applyAround(int x,int y);
	bool isInsideBoundaries(int m,int n);
	double similarity(int p,int s);
	double gauss(double sigma,int x, int y);
	double BilateralFilter::getSpatialWeight(int m, int n,int i,int j);
	void BilateralFilter::setEdgeDetectedImage(IplImage * edimage);
	bool BilateralFilter::isMouseOnEdge(int y,int x);
	
};
