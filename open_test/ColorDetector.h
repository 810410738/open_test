#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
class ColorDetector {
private:
	//最小可接受距离
	int minDist;
	//目标色
	cv::Vec3d target;
	//结果图像
	cv::Mat result;
public:
	ColorDetector();
	~ColorDetector();
	//设置色彩距离阀值。阀值必须是正的，否则设为0
	void setColorDistanceThreshold(int distance);
	//获取色彩距离阀值
	int getColorDistanceThreshold() const;
	//设置需检测的颜色
	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
	void setTargetColor(cv::Vec3b color);
	cv::Vec3b getTargetColor() const;

	cv::Mat process(const cv::Mat &image);
	int getDistance(const cv::Vec3b& color) const;
	
};