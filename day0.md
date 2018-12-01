# Image Processing


## For 8-bit color scheme:
0 is the value for black (or zero intensity of the color channel).
255 is the value for white (or maximum intensity of the color channel).

Image: It is a 2-D Array (for a grayscale image) of numbers that denote the intensity of the color at that pixel. It is a 3-D array for a coloured image. The 3 arrays denote the three channels for Blue, Green and Red.

**Fun Fact**: Pixel = Picture + Element

Therefore the value “0” at a coordinate (0, 0) will represent black at the first pixel. The value “255” at a coordinate (i, j) will represent {white: in case of grayscale image, max. Intensity of red/blue/green: in case of a colored channel}

The combinations of Red, Blue and Green give all the colors in the visible spectrum and hence are used to denote colors.

## C++ Basics:
Objects are variables, data structures, functions or methods which are referenced by an identifier

Mat img ( n_row, _col, CV_8UC3, schar(0) )

Here,
    1. Mat is an object.
    2. Img is the name of the image (identifier)
    3. n_row is the number of rows
    4. n_col is the number of columns
    5. CV_8UC3 is a keyword containing the format type of the imageCV is the openCV library.
      * 8 means 8 bit image(2^8).
      * U means unsigned int values for the intensities.
      * C3 means 3 channels are used.
      * C1 would mean 1 channel is used.
      * schar(0) means the standard character of the matrix is 0 (i.e. black)



### Basic IO differences in C and C++
_____________________________

|    C    |    c++    |
|---------|-----------|
|printf   |    cout   |
|scanf    |    cin    |

_____________________________


### Header File

Header file are files written at the start of the code used to include lots of functions and functionality. They contain a bunch of predefined functions.

The common header files that we encounter are:

* Stdio.h → for C
* IOstream.h → for C++
* Three additional header files of openCV used in C++ are:
  * opencv2/highgui/highgui.hpp
  * opencv2/imgproc/imgproc.hpp
  * opencv2/core/core.hpp

### Difference between a structure and an class:
1. Class is pass-by-reference, struct is pass-by-value.
2. Class can create subclass which can inherit parent’s properties, struct cannot.
3. Informally, Class can contain functions and methods, but struct cannot.


**Pro Tip**: In openCV, the colors are saved as *BGR* channel values.


### The basic code looks something like:

```cpp
#import "opencv2/highgui/highgui.hpp"
#import "opencv2/imgproc/imgproc.hpp"
#import "opencv2/core/core.hpp”


using namespace cv;


int main ()
{
    cvNamedWindow(“win”, WINDOW_NORMAL);
    Mat img(x, y, CV_8UC3, schar(0));


    //------------------//
      CODE HERE
    //------------------//


    imshow(“win”, img);
    waitKey(0);


    return 0;
}
```
### Explanation:

* On lines 1 to 3, we are importing the openCV libraries.
* On line 5 ================BLACK BOX======================
* On line 7 we declare the main function.
* On line 9 we are creating an openCV window named “win” and which will open in the “WINDOW_NORMAL” mode. There are two modes of opening the window.
  * WINDOW_NORMAl → User can resize the window without any constraints.
  * WINDOW_AUTOSIZE → Window size is automatically adjusted to fit the image dimensions. You cannot resize it.
* On line 10, we are creating an object “img” of class “Mat”.We are basically creating an image.
* On line 16, we are using the imshow function to ‘Show’ the “img” image on the “win” window.
* On line 17, we are using a waitKey(0) so that the image is shown on the window till we don’t press anything else. If we use any other value x as waitKey(x), the it will be shown for x milliseconds.
We finally return 0 on line 19.===============WHY?=================


### Functions in Mat:

#### Mat has a function called “at”

```cpp
img.at<uchan>(20, 30) = 255;
```

The pixel at the position (20, 30) has been assigned value of 255. Uchan specifies unary channel (i.e. grayscale).

*Gen. Format for grayscale* → IMGNAME.at<uchan>(ROW.NO, COL.NO)
Can be used to assign or collect value of intensity at that pixel.

*Gen. Format for Colourized* → IMGNAME.at<Vec3b>(ROW.NO, COL.NO)
The value assigned or returned comes in the format {BLUE, GREEN, RED}


#### Mat has two additional functions “rows” and “cols”

```cpp
img.rows
img.cols
```


* img.rows → gives the number of rows in “img” image matrix.
* img.cols → gives the number of columns in the “img” image matrix.



## TASKS:

**TASK 1**: Create a square of 100x100 with red color above the diagonal and yellow below the diagonal.

**TASK 2**: Create a pixel-wise chessboard.

**TASK 3 (pro)**: Create a normal chessboard.


**NOTE**: To compile, put Makefile in the directory, go to the working directory in the terminal, write “make FILENAME” to compile, write “./FILENAME” to run.

--------------------------------------------------------------------------------
** END OF DAY 0 **
--------------------------------------------------------------------------------
