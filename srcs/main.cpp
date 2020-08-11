#include <sys/time.h>
//#include <opencv2/opencv.hpp>
#include "matrix.h"

#define GENERAL
//#define OUTERMOST
//#define TILING

struct timeval start, end;

double convert2ms(struct timeval s, struct timeval e)
{
  return (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec) * 1.0E-6;
}

void calc(float** A, float** B, float** C)
{
#ifdef GENERAL
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < K; ++k)
        C[i][j] += A[i][k] * B[k][j];
#endif
#ifdef OUTERMOST
  for (int k = 0; k < K; ++k)
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        C[i][j] += A[i][k] * B[k][j];
#endif
#ifdef TILING
  for (int mb = 0; mb < M; mb += MTILE)
    for (int nb = 0; nb < N; nb += NTILE)
      for (int k = 0; k < K; ++k)
          for (int i = 0; i < MTILE; ++i)
            for (int j = 0; j < NTILE; ++j) {
              int row = mb + i;
              int col = nb + j;
              C[row][col] += 
                A[row][k] * B[k][col];
            }
#endif

}

int main(int argc, char** argv)
{
  cv::Mat img = cv::imread("./image/luminous.jpg");
  //cv::imshow("Image", img);
  //cv::waitKey(0);
  const int c = img.channels();
  const int h = img.cols;
  const int w = img.rows;

  cv::Mat sample_resized = img;
  cv::Mat sample_float;
  sample_resized.convertTo(sample_float, CV_32FC3);

  //std::vector<cv::Mat> input_channels;
  //for (int i = 0; i < c; ++i) {
  //  cv::Mat channel(h, w, CV_32FC1, )

  //float **A = new float*[M];
  //for (int i = 0; i < M; i++)
  //  A[i] = new float[K];

  //float **B = new float*[K];
  //for (int i = 0; i < K; i++)
  //  B[i] = new float[N];

  //float **C = new float*[M];
  //for (int i = 0; i < M; i++)
  //  C[i] = new float[N];

  //create_matrix(A, B, C);

  //gettimeofday(&start, NULL);
  //calc(A, B, C);
  //gettimeofday(&end, NULL);

  //printf("time = %lf sec.\n", convert2ms(start, end));

  //for (int i = 0; i < M; i++)
  //{
  //  delete[] A[i];
  //  delete[] C[i];
  //  A[i] = 0;
  //  C[i] = 0;
  //}
  //delete[] A;
  //delete[] C;
  //A = 0;
  //C = 0;

  //for (int i = 0; i < K; i++)
  //{
  //  delete[] B[i];
  //  B[i] = 0;
  //}
  //delete B;
  //B = 0;

  return 0;
}
