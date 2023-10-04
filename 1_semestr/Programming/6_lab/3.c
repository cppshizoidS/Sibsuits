#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int i;
  int N = 20;
  float A[N];
  for (i = 0; i < N; i++)
    A[i] = (float)rand() * (10 - 0) / RAND_MAX + 0;
  for (i = 0; i < N; i++)
    printf("\n A[%d]= %0.2f", i, A[i]);
  printf("\n\n");
  for (i = 0; i < N; i++)
    if (i > 0 && i < N - 1) {
      if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
        printf("%.2lf ", A[i]);
      }
    }
}
