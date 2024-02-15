#include "sorting.hpp"
#include <vector>

auto main() -> int {
  std::vector<int> myArray;

  int arraySize = 10000;

  Sorting::measureTime(myArray, Sorting::bubbleSort, "bubble sort", arraySize);
  Sorting::measureTime(myArray, Sorting::selectionSort, "selection sort", arraySize);
  Sorting::measureTime(myArray, Sorting::insertionSort, "insertion sort", arraySize);
}
