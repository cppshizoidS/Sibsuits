#include "binary_search.hpp"

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5,
                          6, 7, 8, 9, 10}; // Пример упорядоченного массива
  int comparisons1 = 0, comparisons2 = 0;
  int position1, position2;

  // Поиск первого элемента массива
  position1 = binarySearchWithKeyAsArg(arr, arr[0], comparisons1);
  comparisons2 = 0; // Сброс счетчика сравнений
  position2 = binarySearchVersion2(arr, comparisons2);

  std::cout << "Поиск первого элемента:" << std::endl;
  std::cout << "Версия 1 - Позиция: " << position1
            << ", Сравнения: " << comparisons1 << std::endl;
  std::cout << "Версия 2 - Позиция: " << position2
            << ", Сравнения: " << comparisons2 << std::endl;

  // Поиск последнего элемента массива
  position1 = binarySearchWithKeyAsArg(arr, arr.back(), comparisons1);
  comparisons2 = 0; // Сброс счетчика сравнений
  position2 = binarySearchVersion2(arr, comparisons2);

  std::cout << "\nПоиск последнего элемента:" << std::endl;
  std::cout << "Версия 1 - Позиция: " << position1
            << ", Сравнения: " << comparisons1 << std::endl;
  std::cout << "Версия 2 - Позиция: " << position2
            << ", Сравнения: " << comparisons2 << std::endl;

  // Поиск элемента, которого нет в массиве
  position1 = binarySearchWithKeyAsArg(arr, 99, comparisons1);
  comparisons2 = 0; // Сброс счетчика сравнений
  position2 = binarySearchVersion2(arr, comparisons2);

  std::cout << "\nПоиск элемента, которого нет в массиве:" << std::endl;
  std::cout << "Версия 1 - Позиция: " << position1
            << ", Сравнения: " << comparisons1 << std::endl;
  std::cout << "Версия 2 - Позиция: " << position2
            << ", Сравнения: " << comparisons2 << std::endl;

  return 0;
}