#include <stdio.h>

int main() {
  int num = 0;

  printf("Please Enter the 4 Numbers\n");
  for (int i = 1; i <= 4; i++) {
    printf("Number %d = ", i);
    scanf("%d", &num);
    if (num < 0) {
      num = 0;
    }
  }
  printf("\n After replace = %d", num);
}
