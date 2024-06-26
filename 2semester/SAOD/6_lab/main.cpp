#include "binary_search.hpp"
#include "ArrFunc.hpp"
#include <iomanip>
#include <iostream> // Include iostream for std::cout and std::cin

int main() {
  int comparisons1 = 0, comparisons2 = 0;
  int position1, position2;

    int size;

    std::cout << "Введите значение: "; 
    std::cin >> size;

    std::cout << "| Size array | Binary Search 1 | Binary Search 2 |\n"; 
    std::cout << "|------------|-----------------|-----------------|\n"; 

    for (size_t len_arr = 100; len_arr <= 1000; len_arr += 100) {
        std::vector<int> arr(len_arr);

        FillInc(arr, len_arr);

        BinarySearch1(arr, len_arr, size);
        BinarySearch2(arr, len_arr, size);

        std::cout << "| " << std::setw(11) << len_arr; 
        std::cout << " | " << std::setw(15) << COMPARE_BINARY_SEARCH_1; 
        std::cout << " | " << std::setw(15) << COMPARE_BINARY_SEARCH_1;
        std::cout << " |\n"; 
    }

    return 0;
}
