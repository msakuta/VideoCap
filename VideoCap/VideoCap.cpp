// VideoCap.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

using namespace cv;

#define WINDOW_NAME "Result"

int process()
{
	VideoCapture cap("0");
	if (!cap.isOpened()) //if this fails, try to open as a video camera, through the use of an integer param
		cap.open(0);
	if (!cap.isOpened()) {
		return 1;
	}
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480.0);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640.0);

	Mat frame;
	cv::namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;
		//-- Show detected matches
		imshow( WINDOW_NAME, frame );


		char key = cv::waitKey(10);

		switch(key) {
			case 27:
				cv::imwrite("test.jpg", frame, vector<int>());
				return 0;
			default:
				break;
		}
		
	}
	return 0;

}

int _tmain(int argc, _TCHAR* argv[])
{
	return process();
}

