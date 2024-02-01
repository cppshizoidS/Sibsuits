/**
 * @file multiplication_table.c
 * @brief Программа для генерации и вывода таблицы умножения.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вывод матрицы на экран.
 * @param matrix Матрица для вывода.
 * @param size Размер матрицы.
 */
void printMatrix(int** matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

/**
 * @brief Главная функция программы.
 * @return Возвращает 0 в случае успешного завершения программы.
 */
int main() {
  int size;

  printf("Введите размер таблицы умножения: ");
  scanf("%d", &size);

  // Выделение памяти под таблицу умножения
  int** multiplicationTable = (int**)malloc(size * sizeof(int*));
  for (int i = 0; i < size; i++) {
    multiplicationTable[i] = (int*)malloc((i + 1) * sizeof(int));
  }

  // Заполнение таблицы умножения
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      multiplicationTable[i][j] = (i + 1) * (j + 1);
    }
  }

  // Вывод таблицы умножения
  printf("Таблица умножения:\n");
  printMatrix(multiplicationTable, size);

  // Освобождение памяти
  for (int i = 0; i < size; i++) {
    free(multiplicationTable[i]);
  }
  free(multiplicationTable);

  return 0;
}
