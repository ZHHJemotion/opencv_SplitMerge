//
//  main.cpp
//  opencv_test3
//
//  Created by ZHHJemotion on 2016/10/6.
//  Copyright � 2016�� Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test3/opencv_test3/opencv_test3/")

using namespace cv;
using namespace std;

// ===================================== Global Function ===============================
//   Describe: the declaration of the global function
// =====================================================================================
bool MultiChannelBlending();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //system("color 5E");
    MultiChannelBlending();
    
    waitKey(1);
    return 0;
}


// =============================  MultiChannelBlending() Function =======================
//   Describe: the realized function of the multiplicate blended channels
// ==================================================================================
bool MultiChannelBlending()
{
    // the defined relative variables
    Mat srcImage;
    Mat logoImage;
    vector<Mat> channels; // Mat means matrix!!! here: vector is a type
    
    // =========================== Blue Channel Session ===========================
    
    Mat imageBlueChannel;
    
    // read image
    logoImage = imread(PATH+string("dota_logo.jpg"),0); // here: we can get the grayscale of dota_logo.jpg
    srcImage = imread(PATH+string("dota_jugg.jpg"));
    
    // Exception Handling
    if(!logoImage.data) {printf("Error: we can't read logoImage!"); return false;}
    if(!srcImage.data) {printf("Error: we can't read srcImage!"); return false;}
    
    // split a 3-channel image to three alone channels image
    split(srcImage, channels);
    
    // ��ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�ڶ��ߵȼۣ��޸�����һ������һ�����ű�
    imageBlueChannel = channels.at(0);
    
    // ��ԭͼ����ɫͨ���ģ�500��250�����괦���·���һ�������logoͼ���м�Ȩ���㣬���õ��Ļ�Ͻ���浽imageBlueChannel��
    addWeighted(imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)), 1.0,logoImage,0.5,0,imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    
    // merge these three alone channels to a 3-channel image
    merge(channels, srcImage);
    
    // show the result
    namedWindow("original&logoBlueChannelIamge");
    imshow("original&logoBlueChannelIamge", srcImage);
                
                
    // =========================== Green Channel Session ===========================
    
    Mat imageGreenChannel;
    
    // read image
    logoImage = imread(PATH+string("dota_logo.jpg"),0); // here: we can get the grayscale of dota_logo.jpg
    srcImage = imread(PATH+string("dota_jugg.jpg"));
    
    // Exception Handling
    if(!logoImage.data) {printf("Error: we can't read logoImage!"); return false;}
    if(!srcImage.data) {printf("Error: we can't read srcImage!"); return false;}
    
    // split a 3-channel image to three alone channels image
    split(srcImage, channels);
    
    // ��ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�ڶ��ߵȼۣ��޸�����һ������һ�����ű�
    imageGreenChannel = channels.at(1);
    
    // ��ԭͼ����ɫͨ���ģ�500��250�����괦���·���һ�������logoͼ���м�Ȩ���㣬���õ��Ļ�Ͻ���浽imageBlueChannel��
    addWeighted(imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)), 1.0,logoImage,0.5,0,imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    
    // merge these three alone channels to a 3-channel image
    merge(channels, srcImage);
    
    // show the result
    namedWindow("original&logoGreenChannelIamge");
    imshow("original&logoGreenChannelIamge", srcImage);

    
    // =========================== Red Channel Session ===========================
    
    Mat imageRedChannel;
    
    // read image
    logoImage = imread(PATH+string("dota_logo.jpg"),0); // here: we can get the grayscale of dota_logo.jpg
    srcImage = imread(PATH+string("dota_jugg.jpg"));
    
    // Exception Handling
    if(!logoImage.data) {printf("Error: we can't read logoImage!"); return false;}
    if(!srcImage.data) {printf("Error: we can't read srcImage!"); return false;}
    
    // split a 3-channel image to three alone channels image
    split(srcImage, channels);
    
    // ��ԭͼ�ĺ�ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�ڶ��ߵȼۣ��޸�����һ������һ�����ű�
    imageRedChannel = channels.at(2);
    
    // ��ԭͼ�ĺ�ɫͨ���ģ�500��250�����괦���·���һ�������logoͼ���м�Ȩ���㣬���õ��Ļ�Ͻ���浽imageBlueChannel��
    addWeighted(imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)), 1.0,logoImage,0.5,0,imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    
    // merge these three alone channels to a 3-channel image
    merge(channels, srcImage);
    
    // show the result
    namedWindow("original&logoRedChannelIamge");
    imshow("original&logoRedChannelIamge", srcImage);

    
    
    return true;
    
}
