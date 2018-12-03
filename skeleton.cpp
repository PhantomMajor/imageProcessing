#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

// reading the image
Mat img= imread("", 1);

int rows=img.rows;
int cols=img.cols;

int main()
{
    namedWindow("win", WINDOW_NORMAL);
    imshow("win", );

    waitKey(0);

    return 0;
}
