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
	//Mat inputImage = imread("grayLena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//Mat outputImage;
	////copyMakeBorder(inputImage, outputImage, 100 - 1, 100 - 1, 100 - 1, 100 - 1, 0);
	////uchar* data = (uchar*)outputImage.data;
	////cout << int(data[0]);
	////cout << outputImage;

	//Blur bl;
	//bl.BlurImage(inputImage, outputImage, 3, 3, 1);
	//imwrite("output.jpg", outputImage);
	//namedWindow("Input image");
	//imshow("Input image", inputImage);
	//namedWindow("Output image");
	//imshow("Output image", outputImage);
	Mat a = Mat(5, 5, CV_8UC1 ,Scalar(0));
	Mat b = Mat(5, 5, CV_8UC1);
	a.at<uchar>(2, 2) = 1;
	vector<float> temp = { 1,2,3,4,5,6,7,8,9 };
	Convolution cv;
	cv.SetKernel(temp, 3, 3);
	cv.DoConvolution(a, b);
	cout << b << endl;
	waitKey(0);
	return 0;
}