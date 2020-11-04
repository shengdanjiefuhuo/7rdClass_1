#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat rotate;
	cv::Mat srcMat=cv::imread("C:/Users/hp/Desktop/5.jpg",1);
	if (srcMat.empty()) return -1;

	float angle = -10.0, scale = 1;

	cv::Point2f center(srcMat.cols*5,srcMat.rows*5);

	const cv::Mat affine_matrixR = cv::getRotationMatrix2D(center,angle,scale);

	cv::warpAffine(srcMat, rotate, affine_matrixR, rotate.size());

	cv::imshow("src", srcMat);
	cv::imshow("rotate", rotate);
	
	cv::Mat fangshe;
	if (srcMat.empty()) return -1;

	const cv::Point2f src_pt[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,100) };
	
	const cv::Point2f dst_pt[] = {
		cv::Point2f(300,100),
		cv::Point2f(300,50),
		cv::Point2f(200,100) };

	const cv::Mat affine_matrixF = cv::getAffineTransform(src_pt, dst_pt);

	cv::warpAffine(srcMat, fangshe, affine_matrixF, srcMat.size());

	cv::imshow("fangshe", fangshe);

	cv::Mat touyin;
	if (srcMat.empty()) return -1;

	const cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(350,150)};

	const cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180)};

	const cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);

	cv::warpPerspective(srcMat, touyin, perspective_matrix, srcMat.size());

	cv::imshow("touyin", touyin);

	waitKey(0);
	
}