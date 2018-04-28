#include "preProcess.hpp"



Mat imagePreProcessing(Mat  image)
{
	Mat element = getStructuringElement( MORPH_ELLIPSE, Size(7, 7), Point( 1, 1) ), element2 = getStructuringElement( MORPH_ELLIPSE, Size(2,2), Point( 1, 1) ), element3 = getStructuringElement( MORPH_ELLIPSE, Size(12, 8), Point( 1, 1) );
	Mat grayImage, Binary, binaryInverted, finalImage, whiteImage = image;
	vector<Mat> channels(3), channels2(3);
	Mat Geq;
	image = createImageMask(image);
	split(image, channels);
	imshow("O_Image", whiteImage);
	if (waitKey(30) >= 0)
		return element;


	equalizeHist(channels[0], channels[0]);	
	equalizeHist(channels[1], channels[1]);	
	equalizeHist(channels[2], channels[2]);	

	threshold( channels[0], channels[0], 200, THRESHOLD_MAX_VALUE, 1);
	threshold( channels[1], channels[1], 250, THRESHOLD_MAX_VALUE, 0);
	threshold( channels[2], channels[2], 200, THRESHOLD_MAX_VALUE, 1);
	merge(channels, finalImage);


	morphologyEx( channels[1], channels[1], 2, element);
	/*channels[1] = channels[1] & channels[0]; 
	morphologyEx( channels[1], channels[1], 2, element2);
	morphologyEx( channels[1], channels[1], 1, element);*/
	

	imshow("R_Image", channels[0]);
	if (waitKey(30) >= 0)
	return element;
	imshow("G_Image", channels[1]);
	if (waitKey(30) >= 0)
		return element;

	vector<Vec3f> circles = houghTransform(channels[1]);
	for(size_t i = 0; i<circles.size();i++)
	{	
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(whiteImage, center, radius, Scalar(0,0,255),1,8,0);	
		cout<<circles[i][0]<<circles[i][1]<<circles[i][2]<<endl;
	}
	

	return whiteImage;

}



vector<Vec3f> houghTransform(Mat image)
{

	vector<Vec3f> circles;
	HoughCircles(image, circles, CV_HOUGH_GRADIENT,1,1,10,10,0,0);	
	return circles;
}


Mat createImageMask(Mat image)
{
	Mat C = Mat::ones(image.rows, image.cols, CV_8UC1);
	C = C*255;
	vector<Mat> channels(3);
	split(image, channels);

	for (int i = 0; i < image.rows;i++)	
	{
			if (i<UP_IMAGE_LIMIT || i>LOW_IMAGE_LIMIT)
			{
				C.row(i) = 0;
			}
		
	}
	channels[0] = channels[0] & C;
	channels[1] = channels[1] & C;
	channels[2] = channels[2] & C;
	merge(channels, image);
	return image;
}


