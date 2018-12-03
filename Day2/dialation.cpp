#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

Mat img= imread("edgedet.jpg", 0);
int rows = img.rows;
int cols = img.cols;

int main()
{
    namedWindow("BinaryImage", WINDOW_NORMAL);
    imshow("BinaryImage", img);
    waitKey(0);

    return 0;
}
