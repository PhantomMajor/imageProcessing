#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

// scale down the image by a factor of 3
int main()
{
    namedWindow("win", WINDOW_AUTOSIZE);
    namedWindow("win_down", WINDOW_AUTOSIZE);

    Mat img = imread("Lena.jpg", 1);

    int rows = img.rows;
    int cols = img.cols;

    int sdf = 2; // scaledown factor

    Mat img_down(rows/sdf, cols/sdf, CV_8UC3, Scalar(0));

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<rows; j++)
        {
            if (rows%sdf == 0 && cols%sdf == 0)
            {
                for (int p=0; p<sdf; p++)
                {
                    for (int q=0; q<sdf; q++)
                    {
                        img_down.at<Vec3b>(i, j) = img.at<Vec3b>(i, j);
                    }
                }
            }
        }
    }

    return 0;
}
