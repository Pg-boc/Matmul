#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void Memoryallocate(float **Z, int x, int y)
{

  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
      Z[i][j] = rand() / (float)RAND_MAX;    
}

void create_matrix(float** A, float** B, float** C)
{
  unsigned int now = (unsigned int)time(0);
  srand(now);

  Memoryallocate(A, M, K);
  Memoryallocate(B, K, N);
  Memoryallocate(C, M, N);

}
