#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat img= imread("index.jpeg", 0);

int rows=img.rows;
int cols=img.cols;

int thresh = 100;
int kernel_gx(int i, int j, Mat img);
int kernel_gy(int i, int j, Mat img);

Mat img_b(img.rows, img.cols, CV_8UC1, Scalar(0));
Mat img_dial(rows, cols, CV_8UC1, Scalar(0));


// to convert the image to grayscale
Mat img_gauss(img.rows, img.cols, CV_8UC1, Scalar(0));
////////////////////////////////////////////////////

void dialation_kernel(int i, int j, Mat img)
{
    int sum = 0;
    for (int p=i-1; p<=i+1; p++)
        for (int q=j-1; q<=j+1; j++)
        {
            if ( img.at<uchar>(p,q) > 0)
            {
                img_dial.at<uchar>(i, j) = 255;
            }
        }
    imshow("win4", img_dial);
}


void update_fun(int t, void*)
{
    for(int i=1; i<rows-1; i++)
        for(int j=1; j<cols-1; j++)
            if (( kernel_gx(i, j, img_gauss) + kernel_gy(i, j, img_gauss) ) < thresh )
            {
                img_b.at<uchar>(i, j) = 255;
            }
            else
            {
                img_b.at<uchar>(i, j) = 0;
            }

    imshow("win2", img_b);

    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
        {
            img_dial.at<uchar>(i, j) = dialation_kernel(i, j, img_b);
        }
    imshow("win2", img_b);

}

/////////////////////////////////////////////////////

int kernel(int i, int j, Mat img)
{
    int sum = 0;
    int count = 0;

    for(int p = i - 1; p <= i + 1; p++)
        for(int q = j - 1; q <= j +1; q++)
        {
            if(p >= 0 && p < rows && q >= 0 && q < cols)
            {
                sum += img.at<uchar>(p , q);
                count++;
            }
        }
    return sum/count;
}

int kernel_gx(int i, int j, Mat img)
{
    int gx = 0;

    for(int p = i - 1; p <= i+1; p++)
        for(int q = j - 1; q <= j + 1; q++)
        {
            if( p >= 0 && p < rows && q >= 0 && q < cols)
            {

                if((p == i && q == j) || (p == i && q == j+1) || (p == i && q == j-1) )
                    gx += ( img.at<uchar>(p , q) ) * 0;

                else if( (p == i - 1 && ( q == j - 1 ||  q == j + 1 || q == j)) )
                    gx += ( img.at<uchar>(p , q) ) * (-1);

                else
                    gx += ( img.at<uchar>(p , q) ) * (+1);
            }
        }

        gx = gx/8;
        return gx*gx;
}

int kernel_gy(int i, int j, Mat img)
{
    int gy = 0;

    for(int p = i - 1; p <= i+1; p++)
        for(int q = j - 1; q <= j + 1; q++)
        {
            if( p >= 0 && p < rows && q >= 0 && q < cols)
            {

                if( (q == j) && ( p == i-1 || p == i || p == i+1 ) )
                    gy += ( img.at<uchar>(p , q) ) * 0;

                else if( (q == j-1) && ( p == i-1 || p == i || p == i+1 ) )
                    gy += ( img.at<uchar>(p , q) ) * (-1);

                else
                    gy += ( img.at<uchar>(p , q) ) * (+1);
            }
        }

        gy = gy/8;
    return gy*gy;
}

int main()
{
    namedWindow("win1", WINDOW_NORMAL);
    namedWindow("win2", WINDOW_NORMAL);
    /*for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            img_gauss.at<uchar>(i, j) = (0.21)*img.at<Vec3b>(i,j)[2] + (0.72)*img.at<Vec3b>(i,j)[1] + (0.07)*img.at<Vec3b>(i,j)[0];
        }
    }*/
    img_gauss=img.clone();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            img_gauss.at<uchar>(i , j) = kernel(i , j, img_gauss);
        }
    }

    namedWindow("win3", WINDOW_AUTOSIZE);
    namedWindow("win4", WINDOW_AUTOSIZE);

    for(int i=1; i<rows-1; i++)
        for(int j=1; j<cols-1; j++)
            if (sqrt( kernel_gx(i, j, img_gauss) + kernel_gy(i, j, img_gauss) ) > thresh )

            {
                img_b.at<uchar>(i, j) = 0;
            }
            else
            {
                img_b.at<uchar>(i, j) = 255;
            }
////////////////////////////////////////////////////////////////
    createTrackbar("tn", "win2", &thresh, 125, update_fun);
////////////////////////////////////////////////////////////////


    imshow("win1", img);
    imshow("win3", img_gauss);

    waitKey(0);

    return 0;
}
