#ifndef SORTING_HPP
#define SORTING_HPP

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <print>
#include <random>
#include <ranges>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace Sorting {

/**
 * @brief Вывод элементов массива в консоль.
 * @tparam T Тип элементов массива.
 * @param arr Массив для вывода.
 */
template <typename T>
constexpr void printArray(const std::vector<T> &arr) {
  for (const auto &elem : arr) {
    std::print("{} ", elem);
  }
  std::println("");
}

/**
 * @brief Шаблонная лямбда для сортировки массива методом пузырька.
 */
constexpr auto bubbleSort = []<typename T>(std::vector<T> &arr) 
  requires std::is_swappable_v<T>
{
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
};

/**
 * @brief Шаблонная лямбда для сортировки массива методом выбора.
 */
constexpr auto selectionSort = []<typename T>(std::vector<T> &arr) 
  requires std::is_swappable_v<T>
{
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      std::swap(arr[i], arr[minIndex]);
    }
  }
};

/**
 * @brief Шаблонная лямбда для сортировки массива методом вставки.
 */
constexpr auto insertionSort = []<typename T>(std::vector<T> &arr) {
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
};


/**
 * @brief Измерение времени выполнения сортировки и вывод результатов.
 * @tparam T Тип элементов массива.
 * @param arr Массив для сортировки.
 * @param sortFunction Функция сортировки.
 * @param sortName Название метода сортировки.
 * @param n Размер массива.
 */
template <typename T, typename Callable>
constexpr void measureTime(const std::vector<T> &arr, Callable sortFunction,
                           const std::string &sortName, int n) {
  // Generate a random array with n elements
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<T> dis(1, 1000);

  arr.resize(n);
  for (int i = 0; i < n; ++i) arr[i] = dis(gen);

  auto start = std::chrono::high_resolution_clock::now();
  sortFunction(tempArr);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::print("Sorted array using: {}\n", sortName);
  if (n <= 20) {
    printArray(tempArr);
  }

  std::print("Time taken by {} for {} elements: {} milliseconds\n\n", 
             sortName, n, duration.count());
}

}  // namespace Sorting
#endif  // SORTING_HPP
