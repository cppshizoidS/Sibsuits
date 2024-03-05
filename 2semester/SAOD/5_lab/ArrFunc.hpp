#ifndef BASE_ARR_FUNCS_HPP
#define BASE_ARR_FUNCS_HPP

/**
 * @file base_arr_funcs.hpp
 * @brief This file contains template functions for manipulating arrays.
 */

#include <cstddef>
#include <iostream>
#include <random>

/**
 * @brief Fill the array with incremental values starting from 0.
 * @tparam T Type of the array elements.
 * @param A The array to be filled.
 * @param len The length of the array.
 */
template <typename T>
void FillInc(T &A, size_t len) {
  for (size_t i = 0; i < len; i++) A[i] = i;
}

/**
 * @brief Fill the array with decremental values starting from (len-1).
 * @tparam T Type of the array elements.
 * @param A The array to be filled.
 * @param len The length of the array.
 */
template <typename T>
void FillDec(T &A, size_t len) {
  for (size_t i = 1; i <= len; i++) A[i - 1] = len - i;
}

/**
 * @brief Fill the array with random values between 0 and 99.
 * @tparam T Type of the array elements.
 * @param A The array to be filled.
 * @param len The length of the array.
 */
template <typename T>
void FillRand(T &A, size_t len) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 99);

  for (auto &element : A) element = dis(gen);
}

/**
 * @brief Calculate the sum of the elements in the array.
 * @tparam T Type of the array elements.
 * @param A The array to be summed.
 * @param len The length of the array.
 * @return The sum of the array elements.
 */
template <typename T>
int CheckSum(const T &A, size_t len) {
  int sum = 0;
  for (const auto &element : A) sum += element;
  return sum;
}

/**
 * @brief Count the number of runs in the array.
 * A run is a sequence of consecutive elements in ascending order.
 * @tparam T Type of the array elements.
 * @param A The array to be analyzed.
 * @param len The length of the array.
 * @return The number of runs in the array.
 */
template <typename T>
size_t RunNumber(const T &A, size_t len) {
  size_t n = 1;
  auto pred = A[0];
  for (const auto &element : A) {
    if (element < pred) n++;
    pred = element;
  }
  return n;
}

/**
 * @brief Print the elements of the array to the standard output.
 * @tparam T Type of the array elements.
 * @param A The array to be printed.
 * @param len The length of the array.
 */
template <typename T>
void PrintMas(const T &A, size_t len) {
  for (const auto &element : A) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

#endif  // BASE_ARR_FUNCS_HPP
