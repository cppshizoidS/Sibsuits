#ifndef LIST_FUNCTIONS_HPP
#define LIST_FUNCTIONS_HPP

#include "List.hpp"
#include <iostream>

namespace list_functions {

// Print elements of the list
template<typename T>
void printList(const single_linked_list<T>& list) {
  for (const auto& item : list) {
    std::cout << item << ' ';
  }
  std::cout << std::endl;
}

// Calculate the checksum of the elements in the list
template<typename T>
int calculateChecksum(const single_linked_list<T>& list) {
  int checksum = 0;
  for (const auto& item : list) {
    checksum += item;
  }
  return checksum;
}

// Count the number of series in the list
template<typename T>
int countSeries(const single_linked_list<T>& list) {
  if (list.empty()) {
    return 0;
  }

  int seriesCount = 1;
  auto prev = list.begin();
  auto curr = prev;

  for (++curr; curr != list.end(); ++curr) {
    if (*curr != *prev) {
      ++seriesCount;
    }
    prev = curr;
  }

  return seriesCount;
}

// Function to remove all elements from the list
template<typename T>
void removeAll(single_linked_list<T>& list) {
  list.clear();
}

// Recursive function to print elements of the list in forward order
template<typename T>
void printForwardRecursive(typename single_linked_list<T>::const_iterator current) {
  if (current != current.cend()) {
    std::cout << *current << ' ';
    printForwardRecursive<T>(++current);
  }
}

// Recursive function to print elements of the list in reverse order
template<typename T>
void printReverseRecursive(typename single_linked_list<T>::const_iterator current) {
  if (current != current.end()) {
    printReverseRecursive<T>(++current);
    --current;
    std::cout << *current << ' ';
  }
}



} // namespace list_functions

#endif // LIST_FUNCTIONS_HPP
