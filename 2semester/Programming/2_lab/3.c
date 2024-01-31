#include <stdio.h>

void decimalToBinary(int n) {
    if (n > 0) {
        decimalToBinary(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int num;
    printf("Введите десятичное число: ");
    scanf("%d", &num);

    printf("Двоичное представление: ");
    decimalToBinary(num);

    return 0;
}
