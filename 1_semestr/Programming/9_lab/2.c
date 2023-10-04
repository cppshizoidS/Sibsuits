#include <stdio.h>

#define N 5

int main() {
    double matrix[N][N] = {
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {6.0, 7.0, 8.0, 9.0, 10.0},
        {11.0, 12.0, 13.0, 14.0, 15.0},
        {16.0, 17.0, 18.0, 19.0, 20.0},
        {21.0, 22.0, 23.0, 24.0, 25.0}
    };
    // Вывод исходной матрицы
    printf("Original matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    // Деление элементов строк на сумму элементов строки
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
        for (int j = 0; j < N; j++) {
            matrix[i][j] /= sum;
        }
    }
    // Вывод измененной матрицы
    printf("Modified matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}