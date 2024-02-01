#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int size;

  printf("Введите размер таблицы умножения: ");
  scanf("%d", &size);

  int **multiplicationTable = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    multiplicationTable[i] = (int *)malloc((i + 1) * sizeof(int));
  }

  // заполнение таблицы умножения
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      multiplicationTable[i][j] = (i + 1) * (j + 1);
    }
  }

  // вывод таблицы умножения
  printf("Таблица умножения:\n");
  printMatrix(multiplicationTable, size);

  // освобождение памяти
  for (int i = 0; i < size; i++) {
    free(multiplicationTable[i]);
  }
  free(multiplicationTable);

  return 0;
}
