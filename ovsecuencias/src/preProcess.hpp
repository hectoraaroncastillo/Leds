// Pre-proccess image.h;
#include <ctype.h>
#include <math.h>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include <stdlib.h>
#include <iostream>
#include "opencv2/calib3d/calib3d.hpp"
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace cv;
using namespace std;

#ifndef THRESHOLD_VALUE
#define	THRESHOLD_VALUE	253
#endif//THRESHOLD_VALUE

#ifndef THRESHOLD_MAX_VALUE
#define	THRESHOLD_MAX_VALUE	255
#endif//THRESHOLD_MAX_VALUE


#ifndef LOW_IMAGE_LIMIT
#define	LOW_IMAGE_LIMIT	190
#endif//LOW_IMAGE_LIMIT

#ifndef UP_IMAGE_LIMIT
#define	UP_IMAGE_LIMIT	50
#endif//UP_IMAGE_LIMIT


Mat imagePreProcessing(Mat  image);
vector<Vec3f> houghTransform(Mat image);
Mat createImageMask(Mat image);

