#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <cstdint>
#include <iostream>
#include <vector>

/**
 * @brief Perform binary search on a sorted vector with the key as a function
 * argument.
 *
 * @param arr The sorted vector to search in.
 * @param key The key to search for.
 * @param comparisons The number of comparisons made during the search (output
 * parameter).
 * @return int The index of the key in the vector. Returns -1 if the key is not
 * found.
 */
constexpr size_t COMPARE_BINARY_SEARCH_1 = 0;
constexpr int ELEMENT_IS_NOT_FOUND = -1;

template <typename TArr, typename TElem>
constexpr int64_t BinarySearch1(const TArr &arr, size_t len, TElem x) {
  size_t COMPARE_BINARY_SEARCH_1 = 0;
  size_t left = 0, right = len - 1;

  while (left <= right) {
    size_t middle = (left + right) / 2;
    COMPARE_BINARY_SEARCH_1++;
    if (arr[middle] == x) return static_cast<int64_t>(middle);

    if (arr[middle] < x)
      left = middle + 1;
    else
      right = middle - 1;
    COMPARE_BINARY_SEARCH_1++;
  }

  return ELEMENT_IS_NOT_FOUND;
}

/**
 * @brief Perform binary search on a sorted vector with the key provided by user
 * input.
 *
 * @param arr The sorted vector to search in.
 * @param comparisons The number of comparisons made during the search (output
 * parameter).
 * @return int The index of the key in the vector. Returns -1 if the key is not
 * found.
 */
template <typename TArr, typename TElem>
int64_t BinarySearch2(const TArr &arr, size_t len, TElem x) {
  int key;
  size_t COMPARE_BINARY_SEARCH_2 = 0;
  std::cout << "Enter the search key: ";
  std::cin >> key;

  int left = 0;
  int right = arr.size() - 1;
  int position = -1;

  while (left < right) {
    size_t middle = (left + right) / 2;
    if (arr[middle] < x)
      left = middle + 1;
    else
      right = middle;
    COMPARE_BINARY_SEARCH_2++;
  }
  COMPARE_BINARY_SEARCH_2++;
  if (arr[right] == x) return static_cast<int64_t>(right);
  return ELEMENT_IS_NOT_FOUND;

  return position;
}

#endif  // SEARCH_HPP
