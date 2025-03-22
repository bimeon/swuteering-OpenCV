#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void noise_gaussian();

int main(void)
{
	noise_gaussian();

	return 0;
}

void noise_gaussian()
{
	// lenna.bmp ������ �׷��̽����� �������� �ҷ��� src�� ����
	Mat src = imread("../../../lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	imshow("src", src);

	// ǥ�� ���� stddev ���� 10, 20, 30�� �ǵ��� for �ݺ����� ����
	for (int stddev = 10; stddev <= 30; stddev += 10) {

		// ����� 0�̰� ǥ�� ������ stddev�� ����þ� ������ �����Ͽ� noise ��Ŀ� ����
		// noise ����� ��ȣ �ִ� ������(CV_32SC1)�� ����ϵ��� �̸� �����Ͽ� randn() �Լ��� ����
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, stddev);

		// �Է� ���� src�� ����þ� ���� noise�� ���Ͽ� ��� ���� dst�� ����
		// dst ������ ���̴� CV_8U�� ����
		Mat dst;
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("stddev = %d", stddev);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}

	destroyAllWindows();
}