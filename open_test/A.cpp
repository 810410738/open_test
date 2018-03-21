#include "stdafx.h"
#include "A.h"

A::A() {

}
A::~A() {

}

void A::Read_Show() {
	const char* imagename = "image/new.jpg";
	//从文件中读入图像
	Mat img = imread(imagename);
	//如果读入图像失败
	if (img.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename);
		exit(0);
	}
	//显示图像
	namedWindow("image", 1);
	imwrite("save.jpg", img);
	imshow("image", img);
	//此函数等待按键，按键盘任意键就返回
	waitKey(0);
}

void A::Visit_Image(){
	const char* imagename = "image/new.jpg";
	//从文件中读入图像
	Mat img = imread(imagename);
	//如果读入图像失败
	if (img.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename);
		exit(0);
	}
	cout << img.rows << endl;
	cout << img.cols << endl;
	if (img.channels() == 3) {
		cvtColor(img, img, CV_BGR2GRAY);
	}
	uchar t;
	imshow("show1", img);
	Mat_<uchar> img1 = Mat::zeros(cvSize(img.cols, img.rows), CV_8U);

	for (int i = 0; i < img.rows/2; i++) {
		for (int j = 0; j < img.cols; j++) {
			//BGR
			//img.at<Vec3b>(j,i)[0] = 255;//blue
			//img.at<Vec3b>(j, i)[1] = 255;
			//img.at<Vec3b>(j, i)[2] = 0;
			t = img.at<uchar>(i, j);
			img.at<uchar>(i, j) = img.at<uchar>(img.rows-i-1,  j);
			img.at<uchar>(img.rows - i - 1, j) = t;
			
		}
	}
	imshow("show2", img);
	
	cvWaitKey(0);
}

void A::Sobel() {
	Mat image = imread("image/new.jpg", 0);
	Mat kernel(3, 3, CV_32F, Scalar(0));
	kernel.at<float>(0, 1) = 1;
	kernel.at<float>(2, 1) = -1;
	kernel.at<float>(1, 1) = 0;
	Mat result;
	filter2D(image, result, CV_8U, kernel, Point(-1, -1));
	imshow("image", image);
	imshow("result", result);
	waitKey(0);
}

void A::add() {
	Mat image1 = imread("image/test.png");
	Mat image2 = imread("image/new.jpg");
	if (image1.empty()) {
		cout << "can't open test.png" << endl;
		exit(0);
	}
	if (image2.empty()) {
		cout << "can't open new.jpg" << endl;
		exit(0);
	}
	Mat result;
	result = image1 + image2;
	//显示图像
	namedWindow("image1", 1);
	imshow("image1", result);
	//此函数等待按键，按键盘任意键就返回
	waitKey(0);
}