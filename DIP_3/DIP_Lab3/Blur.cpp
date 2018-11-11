#include "Blur.h"
int compare(const void * a, const void * b)
{
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a == *(int*)b) return 0;
	if (*(int*)a > *(int*)b) return 1;
}
int Blur::BlurImage(const Mat& sourceImage, Mat& destinationImage, int kWidth, int kHeight, int method) {
	if (method == 0) {
	}
	else if (method == 1) {
		Mat paddedSrcImage;
		copyMakeBorder(sourceImage, paddedSrcImage, kHeight - 1, kHeight - 1, kWidth - 1, kWidth - 1, 0);
		// ảnh output đã được đệm thêm pixel
		Mat paddedDstImage = Mat(sourceImage.rows + 2 * (kHeight - 1), sourceImage.cols + 2 * (kWidth - 1), CV_8UC1, Scalar(0));

		uchar* pPaddedData2 = (uchar*)paddedDstImage.data;
		int heightOfPadded = paddedDstImage.rows, widthOfPadded = paddedDstImage.cols;
		int widthStepOfPadded = paddedDstImage.step[0];
		int nChannelsOfPadded = paddedDstImage.channels();
		uchar* pPoint;

		for (int y = kHeight / 2; y < heightOfPadded - floor(kHeight/2); y++, pPaddedData2 += widthStepOfPadded) {
			uchar* pPaddedRow2 = pPaddedData2;
			for (int x = kWidth / 2; x < widthOfPadded - floor(kWidth/2); x++, pPaddedRow2 += nChannelsOfPadded) {
				int *colorVal;
				colorVal = new int[kHeight*kWidth+1];
				// tìm giá trị màu của các ô lân cận để đưa vào mảng colorVal
				for (int i = 0; i < kHeight; i++) {
					for (int j = 0; j < kWidth; j++) {
						int xInImage, yInImage;// tọa độ của pixel lân cận					
						xInImage = x + (j - (kWidth / 2));
						yInImage = y + (i - (kHeight / 2));
						pPoint = (uchar*)paddedSrcImage.data;
						pPoint += yInImage * widthStepOfPadded + xInImage * nChannelsOfPadded;
						colorVal[i*kHeight + j] = int(pPoint[0]);
					}
				}
				// tìm trung vị
				qsort(colorVal, kHeight*kWidth, sizeof(int), compare);
				pPaddedRow2[0] = colorVal[(kHeight*kWidth)/2];
				delete[] colorVal;
			}
		}
		// crop image
		Rect imgRegion(kWidth - 2, kHeight - 2, sourceImage.cols, sourceImage.rows);
		destinationImage = paddedDstImage(imgRegion);
	}
	else if (method == 2) {
	}
	return 1;
}
Blur::Blur() {

}
Blur::~Blur() {

}
