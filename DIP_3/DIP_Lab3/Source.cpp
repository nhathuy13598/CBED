#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Convolution.h"
#include "Blur.h"
#include "EdgeDetector.h"
using namespace cv;
using namespace std;
int main()
{
	Mat inputImage = imread("grayLena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat outputImage;
	//copyMakeBorder(inputImage, outputImage, 100 - 1, 100 - 1, 100 - 1, 100 - 1, 0);
	//uchar* data = (uchar*)outputImage.data;
	//cout << int(data[0]);
	//cout << outputImage;

	Blur bl;
	bl.BlurImage(inputImage, outputImage, 3, 3, 1);
	imwrite("output.jpg", outputImage);
	namedWindow("Input image");
	imshow("Input image", inputImage);
	namedWindow("Output image");
	imshow("Output image", outputImage);
	waitKey(0);
	return 0;
}