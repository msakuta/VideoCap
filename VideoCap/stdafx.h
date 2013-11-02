// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/features2d.hpp>

#define OPENCVPATH "E:\\OpenCV\\build\\x86\\vc9\\lib\\"

#ifdef _DEBUG
    //Debug���[�h�̏ꍇ
    #pragma comment(lib,OPENCVPATH "opencv_core246d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_imgproc246d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_highgui246d.lib")
/*    #pragma comment(lib,OPENCVPATH "opencv_objdetect243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_contrib243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_features2d243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_flann243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_gpu243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_haartraining_engined.lib")
    #pragma comment(lib,OPENCVPATH "opencv_legacy243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_ts243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_video243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_nonfree243d.lib")
    #pragma comment(lib,OPENCVPATH "opencv_calib3d243d.lib")*/
#else
    //Release���[�h�̏ꍇ
    #pragma comment(lib,OPENCVPATH "opencv_core243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_imgproc243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_highgui243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_objdetect243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_contrib243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_features2d243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_flann243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_gpu243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_haartraining_engined.lib")
    #pragma comment(lib,OPENCVPATH "opencv_legacy243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_ts243.lib")
    #pragma comment(lib,OPENCVPATH "opencv_video243.lib")
#endif