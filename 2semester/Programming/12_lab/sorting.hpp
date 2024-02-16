#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>

namespace Sorting {
/**
 * @brief Вывод элементов массива в консоль.
 * @tparam T Тип элементов массива.
 * @param arr Массив для вывода.
 */
template <typename T> void printArray(const std::vector<T> &arr) {
  for (const auto &elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
/**
 * @brief Сортировка массива методом пузырька.
 * @tparam T Тип элементов массива.
 * @param arr Массив для сортировки.
 */
template <typename T> void bubbleSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
}
/**
 * @brief Сортировка массива методом выбора.
 * @tparam T Тип элементов массива.
 * @param arr Массив для сортировки.
 */
template <typename T> void selectionSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j)
      if (arr[j] < arr[minIndex])
        minIndex = j;

    if (minIndex != i)
      std::swap(arr[i], arr[minIndex]);
  }
}
/**
 * @brief Сортировка массива методом вставки.
 * @tparam T Тип элементов массива.
 * @param arr Массив для сортировки.
 */
template <typename T> void insertionSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}
/**
 * @brief Измерение времени выполнения сортировки и вывод результатов.
 * @tparam T Тип элементов массива.
 * @param arr Массив для сортировки.
 * @param sortFunction Функция сортировки.
 * @param sortName Название метода сортировки.
 * @param n Размер массива.
 */
template <typename T>
void measureTime(std::vector<T> &arr, void (*sortFunction)(std::vector<T> &),
                 const std::string &sortName, int n) {

  // Generate a random array with n elements
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<T> dis(1, 1000);

  arr.resize(n);
  for (int i = 0; i < n; ++i)
    arr[i] = dis(gen);

  auto start = std::chrono::high_resolution_clock::now();
  sortFunction(arr);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Sorted array using: " << sortName << ":\n";
  if (n <= 20)
    printArray(arr);

  std::cout << "Time taken by " << sortName << " for " << n
            << " elements: " << duration.count() << " milliseconds\n\n";
}

}
