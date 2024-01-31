#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // выделение памяти под массив b
    int* b = (int*)malloc(n * sizeof(int));

    // заполнение массива b случайными числами
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        b[i] = rand() % 101 - 50; // случайные числа от -50 до 50
    }

    // подсчет количества положительных и отрицательных чисел
    int positiveCount = 0;
    int negativeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) {
            ++positiveCount;
        } else if (b[i] < 0) {
            ++negativeCount;
        }
    }

    // выделение памяти под массивы c и d
    int* c = (int*)malloc(positiveCount * sizeof(int));
    int* d = (int*)malloc(negativeCount * sizeof(int));

    // заполнение массивов c и d
    int cIndex = 0;
    int dIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) {
            c[cIndex++] = b[i];
        } else if (b[i] < 0) {
            d[dIndex++] = b[i];
        }
    }

    // Вывод исходного массива и полученных массивов
    printf("Исходный массив b: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Массив положительных чисел c: ");
    for (int i = 0; i < positiveCount; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("Массив отрицательных чисел d: ");
    for (int i = 0; i < negativeCount; ++i) {
        printf("%d ", d[i]);
    }
    printf("\n");

    // освобождение памяти
    free(b);
    free(c);
    free(d);

    return 0;
}
