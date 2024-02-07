#include "sorting.hpp"
#include <vector>

auto main() -> int {
  std::vector<int> myArray = {5, 2, 9, 1, 6, 5};

  Sorting::measureTime(myArray, Sorting::bubbleSort, "bubble sort");
  Sorting::measureTime(myArray, Sorting::selectionSort, "selection sort");
  Sorting::measureTime(myArray, Sorting::insertionSort, "insertion sort");
}
