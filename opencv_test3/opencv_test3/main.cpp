//
//  main.cpp
//  opencv_test3
//
//  Created by ZHHJemotion on 2016/10/6.
//  Copyright © 2016年 Lukas_Zhang. All rights reserved.
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
    logoImage = imread(PATH+string("dota_logo.jpg"));
    srcImage = imread(PATH+string("dota_jugg.jpg"));
    
    // Exception Handling
    if(!logoImage.data) {printf("Error: we can't read logoImage!"); return false;}
    if(!srcImage.data) {printf("Error: we can't read srcImage!"); return false;}
    
    // split a 3-channel image to three alone channels image
    split(srcImage, channels);
    
    // 将原图的蓝色通道引用返回给imageBlueChannel,注意是引用，相当于二者等价，修改其中一个另外一个跟着变
    imageBlueChannel = channels.at(0);
    
    // 将原图的蓝色通道的（500，250）坐标处右下方的一块区域和logo图进行加权运算，将得到的混合结果存到imageBlueChannel中
    addWeighted(imageBlueChannel(Rect(400,200,logoImage.cols,logoImage.rows)), 1.0,logoImage,0.5,0,imageBlueChannel(Rect(400,200,logoImage.cols,logoImage.rows)));
    
    // merge these three alone channels to a 3-channel image
    merge(channels, srcImage);
    
    // show the result
    namedWindow("original&logoBlueChannelIamge");
    imshow("original&logoBlueChannelIamge", srcImage);
                
                
                
                
                
                
    return true;
    
}
