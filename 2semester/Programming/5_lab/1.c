#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int** B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, k;

    printf("Введите размер массива A (m): ");
    scanf("%d", &m);

    printf("Введите число k (k<m): ");
    scanf("%d", &k);

    // генерация и заполнение массива A случайными числами
    srand(time(NULL));
    int* A = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        A[i] = rand() % 100 + 1; // случайное число от 1 до 100
    }

    // создание матрицы B
    int rows = m / k + (m % k != 0 ? 1 : 0);
    int cols = k;

    int** B = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)malloc(cols * sizeof(int));
    }

    // заполнение матрицы B из массива A
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < m) {
                B[i][j] = A[index++];
            } else {
                B[i][j] = 0; // дополнение нулями, если m не кратно k
            }
        }
    }

    // вывод массива A
    printf("Массив A:\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");

    // вывод матрицы B
    printf("Матрица B:\n");
    printMatrix(B, rows, cols);

    // освобождение памяти
    free(A);
    for (int i = 0; i < rows; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}
