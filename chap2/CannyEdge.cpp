//
// Created by brayden on 2019-10-01.
//

#include "CannyEdge.h"
#include "opencv2/opencv.hpp"


int cannyedge() {

    cv::Mat img_rgb, img_gry, img_cny;
    cv::namedWindow( "Example Gray",  cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example Canny", cv::WINDOW_AUTOSIZE );
    img_rgb = cv::imread("../satomi.jpg");

    cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::imshow( "Example Gray", img_gry );

    cv::Mat img_pyr, img_pyr2;
    cv::pyrDown( img_gry, img_pyr );
    cv::pyrDown( img_pyr, img_pyr2 );
    cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );

    int x = 16, y = 32;
    cv::Vec3b intensity = img_rgb.at< cv::Vec3b >(y, x);
    uchar blue  = intensity[0];
    uchar green = intensity[1];
    uchar red   = intensity[2];
    std::cout << "At (x,y) = (" << x << ", " << y <<
              "): (blue, green, red) = (" <<
              (unsigned int)blue <<
              ", " << (unsigned int)green << ", " <<
              (unsigned int)red << ")" << std::endl;
    std::cout << "Gray pixel there is: " <<
              (unsigned int)img_gry.at<uchar>(y, x) << std::endl;
    x /= 4; y /= 4;
    std::cout << "Pyramid2 pixel there is: " <<
              (unsigned int)img_pyr2.at<uchar>(y, x) << std::endl;
    img_cny.at<uchar>(x, y) = 128; // Set the Canny pixel there to 128


//    cv::Canny( img_gry, img_cny, 10, 100, 3, true );
    cv::imshow( "Example Canny", img_cny );
    cv::waitKey(0);
    return 0;
}