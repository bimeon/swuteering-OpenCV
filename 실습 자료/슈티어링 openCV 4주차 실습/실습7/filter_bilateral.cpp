#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void filter_bilateral();

int main(void)
{
	filter_bilateral();

	return 0;
}

void filter_bilateral()
{
	Mat src = imread("../../../lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// �׷��̽����� ���� ���� src�� ����� 0�̰� ǥ�� ������ 5�� ����þ� ���� �߰�
	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, 5);
	add(src, noise, src, Mat(), CV_8U);

	// ǥ�� ������ 5�� ����þ� ���͸��� �����Ͽ� dst1�� ����
	Mat dst1;
	GaussianBlur(src, dst1, Size(), 5);

	// �� ������ ǥ�� ������ 10, ��ǥ ������ ǥ�� ������ 5�� ����ϴ� ����� ���͸��� �����Ͽ� dst2�� ����
	Mat dst2;
	bilateralFilter(src, dst2, -1, 10, 5);

	// src, dst1, dst2 ������ ��� ȭ�鿡 ���
	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}