#include <vector>

#include "sorting.hpp"

auto main() -> int {
  std::vector<int> myArray;

  int arraySize = 10000;

  Sorting::measureTime(
      myArray, [](std::vector<int> &arr) { Sorting::bubbleSort(arr); },
      "Bubble sort", arraySize);
  Sorting::measureTime(
      myArray, [](std::vector<int> &arr) { Sorting::selectionSort(arr); },
      "Selection sort", arraySize);
  Sorting::measureTime(
      myArray, [](std::vector<int> &arr) { Sorting::insertionSort(arr); },
      "Insertion sort", arraySize);
}