#ifndef SORTING_HPP
#define SORTING_HPP

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

namespace Sorting {

template <typename T> void printArray(const std::vector<T> &arr) {
  for (const auto &elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

template <typename T> void bubbleSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
}

template <typename T> void selectionSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j)
      if (arr[j] < arr[minIndex])
        minIndex = j;
  }
}

template <typename T> void insertionSort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
      arr[j + 1] = arr[j];
    --j;

    arr[j + 1] = key;
  }
}

template <typename T>
void measureTime(std::vector<T> &arr, void (*sortFunction)(std::vector<T> &),
                 const std::string &sortName) {

  auto start = std::chrono::high_resolution_clock::now();
  sortFunction(arr);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "Sorted array using: " << sortName << ":\n";
  printArray(arr);
  std::cout << "Time taken by: " << sortName << ":" << duration.count()
            << "microseconds\n\n";
}

} // namespace Sorting

#endif // !SORTING_HPP
