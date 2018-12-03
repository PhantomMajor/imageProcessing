#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
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

/* creating a 2D boolean array globally to denote
whether the pixel has been visited or not.
0 -- not visited
1 -- visited
*/
bool **isVisited;

// create the isValid function
bool isValid(int i, int j)
{
    if ( i < rows && i >= 0 && j < cols && j >= 0)
        return 1; // i.e the pixel is valid
    else
        return 0;
}

// create the bfs function body
void BFS(int i, int j)
{
    queue <point> MQ; // queue of the unvisited neighbours
    point p1; // create a point

    // initialize the created point
    p1.x = i;
    p1.y = j;

    MQ.push(p1); // push the point in the queue

    while( ! MQ.empty() )
    {
        p1 = MQ.front();

        MQ.pop();

        for (int l= p1.x-1; l<=p1.x+1; l++ )
        {
            // printf("Hello Outer\n"); // BUGGER
            for (int m= p1.y-1; m<=p1.y+1; m++)
            {
                if ( (isValid(l, m) == 1) && (img_in.at<uchar>(l, m) < thresh) && (isVisited[l][m] == 0) )
                {
                    point p2;
                    p2.x = l;
                    p2.y = m;

                    img_out.at<uchar>(l, m) = 0; // print the block(l, m) on image out

                    // update the isVisited array
                    isVisited[l][m] = 1; // since this element has been visited

                    // push the neighbour since it has been visited
                    MQ.push(p2);
                }
            }
        }
    }
}

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

    // linear search to the firsts white pixel
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if (img_in.at<uchar>(i, j) < thresh && isVisited[i][j] == 0)
            {
                // print this pixel to the img_out
                img_out.at<uchar>(i, j) = 0;

                // apply the bfs algo as soon as the black pixel is touched
                BFS(i, j);
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
