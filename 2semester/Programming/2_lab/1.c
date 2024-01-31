#include <stdio.h>

void printPositiveNumbers() {
    int num;
    scanf("%d", &num);

    if (num != 0) {
        if (num > 0) {
            printf("%d\n", num);
        }
        printPositiveNumbers(); 
    }
}

int main() {
    printf("Введите последовательность чисел (0 для завершения):\n");
    printPositiveNumbers();
    return 0;
}
