#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

// scale up the image by a factor of 3
int main()
{
    namedWindow("win", WINDOW_AUTOSIZE);
    namedWindow("win_su", WINDOW_AUTOSIZE);
    Mat img = imread("Lena.jpg", 1);
    int rows = img.rows;
    int cols = img.cols;

    int suf = 3; // it can be any number

    // scaled up image
    Mat img_up(suf*rows, suf*cols, CV_8UC3, Scalar(0));

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            for (int p=0; p<suf; p++)
            {
                for (int q=0; q<suf; q++)
                {
                    img_up.at<Vec3b>(i+p, j+q) = img.at<Vec3b>(i, j);
                }
            }
        }
    }

    printf("Rows new: %d\n", img_up.rows);
    printf("Rows: %d\n", img.rows);

    imshow("win", img);
    imshow("win_su", img_up);
    waitKey(0);

    return 0;
}
