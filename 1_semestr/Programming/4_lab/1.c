#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // S= 1+ 2 + 3+...+ 117;  (s=6903)
  int S = 0;
  for (int i = 1; i < 118; i++) {
    S += i;
  }
  printf("S= %d \n", S);
}
