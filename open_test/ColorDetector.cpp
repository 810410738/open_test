#include "stdafx.h"
#include "ColorDetector.h"
#include<iostream>
ColorDetector::ColorDetector() :minDist(100) {
	target[0] = target[1] = target[2] = 0;
}
ColorDetector::~ColorDetector() {

}
void ColorDetector::setColorDistanceThreshold(int distance) {
	if (distance < 0) {
		distance = 0;
	}
	minDist = distance;
}
int ColorDetector::getColorDistanceThreshold() const {
	return minDist;
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue) {
	target[0] = blue;
	target[1] = green;
	target[2] = red;
}

void ColorDetector::setTargetColor(cv::Vec3b color) {
	target = color;
}

cv::Vec3b ColorDetector::getTargetColor() const {
	return target;
}

cv::Mat ColorDetector::process(const cv::Mat &image) {
	result.create(image.rows, image.cols, CV_8U);
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	//对于每个像素
	for (; it != itend; it++, itout++) {
		if (getDistance(*it) < minDist) {
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	return result;
}

int ColorDetector::getDistance(const cv::Vec3b& color) const {
	return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
}