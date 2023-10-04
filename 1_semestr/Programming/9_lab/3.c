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
    // Транспонирование матрицы
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // Вывод транспонированной матрицы
    printf("Transposed matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}