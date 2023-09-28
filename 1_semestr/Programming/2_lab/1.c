#include <stdio.h>

int main() {
  int num, sum = 0, product = 1, diff = 0;

  printf("Please Enter the 6 Numbers\n");
  for (int i = 1; i <= 6; i++) {
    printf("Number %d = ", i);
    scanf("%d", &num);
    sum += num;
    product *= num;
  }
  if (sum > product) {
    diff = sum - product;
    printf("\n The sum is greater then product on = %d", diff);
  } else {
    diff = product - sum;
    printf("\n The product is greater then sum on = %d", diff);
  }
  printf("\nThe Sum of 6 Numbers     = %d", sum);
  printf("\nThe Product of 6 Numbers = %d\n", product);
}
