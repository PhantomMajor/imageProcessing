#import "opencv2/highgui/highgui.hpp"
#import "opencv2/imgproc/imgproc.hpp"
#import "opencv2/core/core.hpp"

using namespace cv;

int main ()
{
    // image of dimensions 500 x 500
    Mat img(500, 500, CV_8UC3, schar(0));
    cvNamedWindow("win", WINDOW_NORMAL);

    int rows = img.rows;
    int cols = img.cols;

    for (int i= 0; i< rows; i++)
    {
        // vary i(row index) from 0 to rows(500)
        for (int j= 0; j< cols-i; j++)
        {
            // vary j(col index) from 0 to (diagonal element)
            img.at<Vec3b>(i, j) = {0, 0, 255};// red color
        }
        for  (int j=cols-i-1; j>=0; j--)
        {
            // vary j(col index) from last col to diagonal element
            img.at<Vec3b>(i, j) = {0, 255, 255};// yellow color
        }
    }

    imshow("win", img);
    waitKey(0);

    return 0;
}
