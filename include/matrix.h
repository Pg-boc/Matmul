#ifndef MATRIX
#define MATRIX

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>

#define M 1024
#define N 1024
#define K 1024

#define MTILE 32
#define NTILE 32
#define KTILE 32

void create_matrix(float** A, float** B, float** C);
#endif // MATRIX
