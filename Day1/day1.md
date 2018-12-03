# DAY 1

The day started with a Task of making a mirror image.


**TASK 1**: Make a mirror image of Lena(the famous IP image)

The homework task was to make the water image of Lena.


**TASK 2**: Make a water image of Lena.

## Grayscale:

Image in which the value of each pixel is a representing only an amount of light. It carries only intensity information. The weakest intensity is the black color at the value 0 and teh strongest intensity is white at the value 255.

__To convert An RGB image to Grayscale Image, we have three methods:__

**Method 1**:
The Average Value of the pixel. We take the average of the R, G and the B values of the pixels.

```
pixelValue_grayscale =( pixelValue(R) + pixelValue(G) + pixelValue(B) ) / 3;
```
Exemplar cpp code:
```cpp
img_gray.at<uchar>(12,45) =( img_RGB.at<Vec3b>(12,45)[0] + img_RGB.at<Vec3b>(12,45)[1] + img_RGB.at<Vec3b>(12,45)[2] ) / 3;
```

**Method 2**:
The maximum and the minimum vlue of the three channels at that pixel are averaged out.

Exemplar cpp code:
```cpp
// find the max using a function or a library
int max = Max(img_RGB.at<Vec3b>(12,45)[0],  img_RGB.at<Vec3b>(12,45)[1], img_RGB.at<Vec3b>(12,45)[2]);

// find the min using a function or a library
int min = Min(img_RGB.at<Vec3b>(12,45)[0],  img_RGB.at<Vec3b>(12,45)[1], img_RGB.at<Vec3b>(12,45)[2]);

// Conversion of the pixel into a grayscale pixel
img_gray.at<uchar>(12,45) = (max + min) / 2;
```

***Note to Self:*** _Write the Max and min functions when you get time._

**Method 3**:
***The Gaussian Method***

The human eye is more sensitive to certain lights than others. Hence, to eleminate this bias, we assign specific weights to the diferent channels.

 R | G | B
---|---|---
 .21|.72|.07

Exemplar cpp code:
```cpp
// weighted walues of the pixels
int w_red = (0.21) * img_RGB.at<Vec3b>(12,45)[2];
int w_green = (0.72) * img_RGB.at<Vec3b>(12,45)[1];
int w_blue = (0.07) * img_RGB.at<Vec3b>(12,45)[0];

img_gray_gauss.at<uchar>(12,45) = w_red + w_green + w_blue ;
```


**TASK 3**: Convert an image to grayscale using three methods.

## Thresholding:

The Process in which all the values _above_ OR _below_ a certain value (called the _threshold value_) is discarded and the other values are reassigned to their maximum values.

This is easily done by adding a simple if-else conditional statement inside the nested for-loops.

Examplar cpp code;
```cpp
int threshold = 125; // any integer value between 0 and 255

int rows = img.rows;
int cols = img.cols;

// here, we traverse the image applying the conditional
for(int i=0; i<rows; i++)
{
    for(int j=0; j<cols; j++)
    {
        // Now while traversing individual elements, we apply our conditionals.
        if(img.at<uchar>(i, j) < threshold)
        {
            // since the grayscale pixel value is below the threshold, we switch it off.
            img.at<uchar>(i, j) = 0;
        }
        else
        {
            // since the grayscale pixel value is above the threshold, we switch it to the maximum intensity.
            img.at<uchar>(i, j) = 255;
        }
    }
}

```

---

## TRACKBAR:

**Important**

A trackbar is a slider that we can create that can dynamically change the values of the threshold.

i.e. we do not have to run the program 256 times to check for different threshold values. We can easily change it while the program is running!

***Note to Self:*** _Add an image when you get time._

## Callback Function:

A callback function takes another function as an argument. It can be a recursively nested function.

## createTrackbar:
It is a callback function which creates a Trackbar.

Syntax:
```cpp

void updateFunction(int t, void*); // declare the updateFunction.

createTrackbar(
    "trackbarName", "windowName", &t, 255, updateFunction
);

/* createTrackbar
* "trackbarName" -- Specifies teh name of the trackbar
* "windowName" -- Specifies the window in which the image is present and the trackbar will be present.
* &t -- address of the pointer to the variable( the threshold in our case), that we want to change.
* 255 -- the upper limit of the trackbar.
* updateFunction -- the function which will be called to update the value of the changed parameter
*/

void updateFunction(int t, void*)
{
    // PREVIOUS CODE

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(img.at<uchar>(i, j) < t)
            {
                img.at<uchar>(i, j) = 0;
            }
            else
            {
                img.at<uchar>(i, j) = 255;
            }
        }
    }
}

```
void * is used for recursive calling.


**TASK 3**: Create 3 trackbars of RBG values.

---

## Image Segmentation:

In computer vision, image segmentation is the process of partitioning a digital image into multiple segments (sets of pixels, also known as super-pixels).

It is done to make it easier to read and analyze the image. It is usually done to locate objects and boundaries.

To do image segmentation, we create a "band filter". We put an upper threshold and a lower threshold on our image. This enables us to select a particular "band" of the visible spectrum. We will have two trackbars for this purpose.

Band filter allows us to "take out" a particular color-band from the image.


### Brightness and Contrast:

Brightness is a relative term. We can define it to be the intensity of light from the entire image. Brightness can be easily increased or decreased by simple **addition or substraction** of a constant number from the image matrix.

Contrast can easily be explained by the difference between the maximum and te minimum pixel intensity. Contrast is found by finding the minimum and the maximum pixel intensity in the image matrix and then finding their difference. It can be increased or decreased by simple **multiplication or division** of a constant to the image matrix.

---

## Blur and Noise-Cancellation:

Noise can be defined as  unwanted or random signals in the image. Eg. Salt and pepper noise.

#### Blur
It is an effect that is used to reduce the "_Noise_" in an image and also reduce the detail in it.

#### Noise-Cancellation
It is the process of reducing or eliminating the _noise_"" in the input image. It can be used for edge detection.



####  Kernel
A Kernel is just a small matrix that is moved over the image to:
1. Blur
2. Sharpen
3. Emboss
4. Detect edges

and a lot more things. It is also called a convolution matrix or a mask.


There are three main methods of blurring the image:
1. Mean (used mainly for Salt-and-pepper-noise)
2. Median
3. Gaussian (most widely used)

|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   ||

If this is the 8x8 image matrix, then the kernel liiks like:

|   |   |   |     
|---|---|---|
|   |   |   |
|   |   |   ||

This is the 3x3 Kernel that will move(convolute) over the image matrix.

* The logic for mean-blur is that we take the average of the pixels that are in the cells of the Kernel and put the average value in the _center pixel_.

This can be seen as:

|  1/2 | 1/2  | 1/2  |     
|---|---|---|
| 1/2  | 1/2  | 1/2  |
|  1/2 | 1/2  | 1/2  |

This is the weighted matrix which will move on the image matrix and it'll keep putting the **average** value in the centeral pixel.

* In the median type, we take the median of the values in the kernel and put it in the middle pixel.

* In the Gaussian method, we take into account the statistical importance of different cells of the matrix. The centeral cell is the most significant, next being edge cells. The corner cells are least significant. Hence the kernel (matrix with the weights) looks like:

|  1/16 | 1/8  | 1/16 |     
|---|---|---|
| 1/8  | 1/4  | 1/8  |
|  1/16 | 1/8  | 1/16  |

This is based on the Gausssian bell curve in which the data is maximum around the center.

To create a Kernel, we loop over two different parameters.
The exemplar code is:

```cpp

int kernel (int i, int j, Mat img)
{
    int sum=0;
    for (int p=i-1; p<= i+1; p++)
    {
        for (int q=j-1; q<= j+1; q++)
        {
            // The algorithm for the kernel's function comes here.
            // some operation using conditionals to find the sum.
        }
    }
    return sum;
}


for (int i=0; i<rows; i++)
{
    for (int j=0; j<cols; j++)
    {
        img_new.at<Vec3b>(i, j) = kernel(i, j, img_old);
    }
}


```

**NOTE**: Here for gaussian blur, the logic that if the center piece is even, then the corner pieces will be even and so on can be used. Simpler method is to define for each case. Computationally, it is similar.

---

## Histogram:

A histogram is a graph of frequency of a quantity. An image histogram shows the frequency of the pixel intensities.

The image is first converted into a grayscale image and then teh corresponding histogram is plotted with the frequency on the Y-Axis and the pixel intensity on the X-Axis.

Histograms can also be plotted for single channels of a coloured image.

Hustograms can be used to:
* Tell about the warmth of an image.
* Adjust the brightness and the contrast.
* Equalize an image(?!)
* Threshold the image (widely used in Comp.Vision)

An image having more red colour, is said to be warmer; and one with more blue, is said to be colder.

---

Things to do with the image:
1. Resize
    * Zoom-in
    * Zoom-out
2. Morphing
3. Rotation

**Morphing** When we overlap two images. To implement it, wejust have to add intensities of the two images. The two images must be of teh same size.

We can give one image the weight (1-t) and the other the weight t, where t is between 0 and 1. Using a Trackbar, we can also determine the level of morph of the two images.
