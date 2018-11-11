#include "Convolution.h"



vector<float> Convolution::GetKernel() {
	return _kernel;
}

void Convolution::SetKernel(vector<float> kernel, int kWidth, int kHeight) {
	_kernel = kernel;
	_kernelWidth = kWidth;
	_kernelHeight = kHeight;
}

int Convolution::DoConvolution(const Mat& sourceImage, Mat& destinationImage) {
	// Giả định rằng ma trận có kích thước là số lẻ và là ma trận vuông
	int rows = sourceImage.rows;
	int cols = sourceImage.cols;
	int kernelIndex = _kernelWidth / 2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int sum = 0;
			for (int s = -kernelIndex; s <= kernelIndex; s++) {
				for (int t = -kernelIndex; t <= kernelIndex; t++) {
					int indexX = s + kernelIndex;
					int indexY = t + kernelIndex;
					int index = _kernelWidth * indexX + indexY;
					if (i - s >= 0 && j - t >= 0 && i - s < rows && j - t < cols) {
						sum += int(_kernel[index] * sourceImage.at<uchar>(i - s, j - t));
						
					}
					
				}
			}
			destinationImage.at<uchar>(i,j) = sum;
		}
	}
	return 1;
}

Convolution::Convolution() {
	_kernelWidth = 0;
	_kernelHeight = 0;
}
Convolution::~Convolution() {

}
