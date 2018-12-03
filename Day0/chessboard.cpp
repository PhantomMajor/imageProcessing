#import "opencv2/highgui/highgui.hpp"
#import "opencv2/imgproc/imgproc.hpp"
#import "opencv2/core/core.hpp"

using namespace cv;

int main ()
{
    // image of dimensions 1200 x 1200
    Mat img(1200, 1200, CV_8UC3, schar(0));
    cvNamedWindow("win", WINDOW_NORMAL);

    int rows = img.rows;
    int cols = img.cols;

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if ((i+j)%2 == 0)
            {
                img.at<Vec3b>(i,j) = {0, 0, 0}; // black color
            }
            else
            {
                img.at<Vec3b>(i,j) = {255, 255, 255}; // white color
            }
        }
    }

    imshow("win", img);
    waitKey(0);

    return 0;
}
