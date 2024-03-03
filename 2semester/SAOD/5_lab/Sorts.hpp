#ifndef SORTS_HPP
#define SORTS_HPP

#include "ArrFunc.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
/**
 * @brief Swap the values of two variables.
 * @tparam T Type of the variables.
 * @param x First variable.
 * @param y Second variable.
 */
template <typename T> void Swap(T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}
/**
 * @brief Print the sorted array along with the number of moves and comparisons.
 * @tparam T Type of the array elements.
 * @param A The array to be printed.
 * @param m Number of moves performed during sorting.
 * @param c Number of comparisons performed during sorting.
 */
template <typename T> void PrintArr(const T &A, size_t m, size_t c) {
  std::cout << "Sort array: ";
  PrintMas(A);
  std::cout << "Move: " << m << std::endl;
  std::cout << "Compare: " << c << std::endl;
}
/**
 * 1 lab
 * @brief Perform selection sort on the array.
 * @tparam T Type of the array elements.
 * @param A The array to be sorted.
 * @return Total number of moves and comparisons during sorting.
 */
template <typename T> size_t SelectSort(T &A) {
  size_t m = 0, c = 0;
  size_t len = A.size();
  for (size_t i = 0; i < len - 1; i++) {
    auto minIndex = std::min_element(A.begin() + i, A.end()) - A.begin();
    Swap(A[i], A[minIndex]);
    m += 3;
    c += len - i - 1;
  }
  // PrintArr(A, m, c);
  return m + c;
}
/**
 * 2 lab
 * @brief Perform bubble sort on the array.
 * @param T Type of the array elements.
 * @param A The array to be sorted.
 * @return Total number of moves and comparisons during sorting.
 */
template <typename T> size_t BubbleSort(T &A) {
  size_t m = 0, c = 0;
  size_t len = A.size();
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 1; j < len - i; j++) {
      if (A[j] < A[j - 1]) {
        Swap(A[j], A[j - 1]);
        m += 3;
      }
      c++;
    }
  }
  // PrintArr(A, m, c);
  return m + c;
}
/**
 * 3 lab
 * @brief Perform shaker sort (or cocktail sort) on the array.
 * @tparam T Type of the array elements.
 * @param A The array to be sorted.
 * @return Total number of moves and comparisons during sorting.
 */
template <typename T> size_t ShakerSort(T &A) {
  size_t L = 0, R = A.size() - 1, k = A.size() - 1;
  size_t m = 0, c = 0;
  do {
    for (size_t j = R; j > L; j--) {
      if (A[j] < A[j - 1]) {
        Swap(A[j], A[j - 1]);
        m += 3;
        k = j;
      }
      c++;
    }
    L = k;
    for (size_t j = L; j < R; j++) {
      if (A[j] > A[j + 1]) {
        Swap(A[j], A[j + 1]);
        m += 3;
        k = j;
      }
      c++;
    }
    R = k;
  } while (L < R);
  // PrintArr(A, m, c);
  return m + c;
}
/**
 * 4 lab
 * @brief Perform insertion sort on the array.
 * @tparam T Type of the array elements.
 * @param A The array to be sorted.
 * @return Total number of moves and comparisons during sorting.
 */
template <typename T> size_t InsertionSort(T &A, size_t len) {
  size_t m = 0, c = 0;
  for (size_t i = 1; i < len; i++) {
    bool f = true;
    auto t = A[i];
    long long j = i - 1;
    while (j > -1 and t < A[j]) {
      f = false;
      A[j + 1] = A[j];
      j--;
      c++;
      m++;
    }
    if (f)
      c++;
    A[j + 1] = t;
    m += 2;
  }
  return m + c;
}
/**
 * 5 lab
 * @brief Perform shell sort on the array
 *
 * @tparam T Type of the array elements.
 * @param A The array to be sorted.
 * @return Total number of moves and comparisons during sorting.
 */
template <typename T> size_t ShellSort(T &A) {
  size_t m = 0, c = 0;
  size_t len = A.size();
  for (size_t gap = len / 2; gap > 0; gap /= 2) {
    for (size_t i = gap; i < len; i++) {
      auto temp = A[i];
      size_t j;
      for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
        A[j] = A[j - gap];
        m += 3;
        c++;
      }
      A[j] = temp;
      m += 2;
    }
  }
  // PrintArr(A, m, c);
  return m + c;
}
#endif
