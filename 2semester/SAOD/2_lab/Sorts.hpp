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
 * @brief Perform bubble sort on the array.
 * @tparam T Type of the array elements.
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

#endif // SORTS_HPP