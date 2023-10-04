#include <stdio.h>

#define ROWS 10
#define COLS 20

void swap_rows(int matrix[ROWS][COLS], int row1, int row2) {
    for (int j = 0; j < COLS; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

int main() {
    int matrix[ROWS][COLS];
    // Заполнение матрицы случайными значениями
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = i * COLS + j;
        }
    }
    // Вывод исходной матрицы
    printf("Original matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Перестановка строк
    for (int i = 0; i < ROWS; i += 2) {
        swap_rows(matrix, i, i+1);
    }
    // Вывод измененной матрицы
    printf("Modified matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}