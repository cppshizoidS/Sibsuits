#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <vector>

/**
 * @brief Perform binary search on a sorted vector with the key as a function argument.
 * 
 * @param arr The sorted vector to search in.
 * @param key The key to search for.
 * @param comparisons The number of comparisons made during the search (output parameter).
 * @return int The index of the key in the vector. Returns -1 if the key is not found.
 */
inline int binarySearchWithKeyAsArg(const std::vector<int> &arr, int key,
                                     int &comparisons) {
  int left = 0;
  int right = arr.size() - 1;
  int position = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    comparisons++;

    if (arr[mid] == key) {
      position = mid;
      break;
    } else if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return position;
}

/**
 * @brief Perform binary search on a sorted vector with the key provided by user input.
 * 
 * @param arr The sorted vector to search in.
 * @param comparisons The number of comparisons made during the search (output parameter).
 * @return int The index of the key in the vector. Returns -1 if the key is not found.
 */
inline int binarySearchVersion2(const std::vector<int> &arr, int &comparisons) {
  int key;
  std::cout << "Enter the search key: ";
  std::cin >> key;

  int left = 0;
  int right = arr.size() - 1;
  int position = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    comparisons++;

    if (arr[mid] == key) {
      position = mid;
      break;
    } else if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return position;
}

#endif // SEARCH_HPP
