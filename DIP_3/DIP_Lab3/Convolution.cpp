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
	return 1;
}

Convolution::Convolution() {
	_kernelWidth = 0;
	_kernelHeight = 0;
}
Convolution::~Convolution() {

}
