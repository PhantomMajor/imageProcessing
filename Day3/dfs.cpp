#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<queue>

using namespace cv;
using namespace std;

int blackBodyCounter;

// create a structure for a point
typedef struct _point{
    int x; // to store the x coordinate(or the i value)
    int y; // to store the y coordinate(or the j value)
} point;

// reading the binary image
Mat img_in= imread("dfs_path.jpg", 0);

int rows=img_in.rows;
int cols=img_in.cols;

// creating the output image globally
Mat img_out(rows, cols, CV_8UC1, Scalar(255));

int thresh = 125;

bool **isVisited;

// create the isValid function
bool isValid(int i, int j)
{
    if ( i < rows && i >= 0 && j < cols && j >= 0)
        return 1; // i.e the pixel is valid
    else
        return 0;
}

// create the dfs function body
DFS_visit()

int main()
{
    isVisited = (bool** )malloc(sizeof(bool*) * rows);
    for (int i=0; i<rows; i++)
    {
        isVisited[i] = (bool* )malloc(sizeof(bool) * cols);
    }

    blackBodyCounter = 0;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            isVisited[i][j] = 0;
        }
    }

    // linear search to the first white pixel
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if (img_in.at<uchar>(i, j) < thresh && isVisited[i][j] == 0)
            {
                // print this pixel to the img_out
                img_out.at<uchar>(i, j) = 0;

                // apply the bfs algo as soon as the black pixel is touched
                DFS(i, j);
                blackBodyCounter++; // increase the black body counter by one
            }
        }
    }

    namedWindow("win_in", WINDOW_NORMAL);
    imshow("win_in", img_in);
    namedWindow("win_out", WINDOW_NORMAL);
    imshow("win_out", img_out);

    printf("The number of black bodies is: %d\n", blackBodyCounter);

    waitKey(0);

    return 0;
}
