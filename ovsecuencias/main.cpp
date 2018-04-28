#include "src/preProcess.hpp"

int main() 
{
    	VideoCapture camera(1);   ///*** Open the camera, index indicates the number of device. 
	camera.set(CV_CAP_PROP_FRAME_WIDTH,320);
	camera.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	Mat cameraFrame;
	
	if (!camera.isOpened()) 
	{ 
		return 0xFF;
	}

	while (true) 
	{
		camera.read(cameraFrame);
		cameraFrame = imagePreProcessing(cameraFrame);
		imshow("Image", cameraFrame);
		if (waitKey(30) >= 0)
		break;
	}

}


