#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat img= imread("edgedet.jpg", 0);

int rows=img.rows;
int cols=img.cols;
Mat img_dial(rows, cols, CV_8UC1, Scalar(0));

void dialation_kernel(void)
{
    int sum = 0;
    int i, j, p,q;
    int flag;
    for (i=0; i<rows; i++)
        for (j=0; j<cols; j++)
            flag=0;
            for (p=i-1; p<=i+1; p++)
                for (q=j-1; q<=j+1; q++)
                    if(img.at<uchar>(p,q)==0)
                        flag=1;
            if ( flag==1)
                img_dial.at<uchar>(i,j)= 255;
            else
                img_dial.at<uchar>(i,j)= 0;

    imshow("win2", img_dial);
}

int main()
{
    namedWindow("win", WINDOW_NORMAL);
    namedWindow("win2", WINDOW_NORMAL);
    dialation_kernel();
    imshow("win", img);
    // imshow("win2", img_dial);

    waitKey(0);

    return 0;
}
