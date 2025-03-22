#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void filter_median();

int main(void)
{
	filter_median();

	return 0;
}

void filter_median()
{
	Mat src = imread("../../../lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// src ���󿡼� 10%�� �ش��ϴ� �ȼ� ���� 0 �Ǵ� 255�� ����
	int num = (int)(src.total() * 0.1);
	for (int i = 0; i < num; i++) {
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (i % 2) * 255;
	}

	// ǥ�� ������ 1�� ����þ� ���͸��� �����Ͽ� dst1�� ����
	Mat dst1;
	GaussianBlur(src, dst1, Size(), 1);

	// ũ�Ⱑ 3�� �̵�� ���͸� �����Ͽ� dst2�� ����
	Mat dst2;
	medianBlur(src, dst2, 3);

	// src, dst1, dst2 ������ ��� ȭ�鿡 ���
	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}