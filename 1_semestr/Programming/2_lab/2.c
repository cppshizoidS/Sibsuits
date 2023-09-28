#include <stdio.h>

int main() {
  int num, sum = 0;

  printf("Please Enter the 5 Numbers\n");
  for (int i = 1; i <= 5; i++) {
    printf("Number %d = ", i);
    scanf("%d", &num);
    if (num > 0) {
      sum += num;
    }
  }
  printf("\nThe Sum of Positive Numbers     = %d", sum);
}
