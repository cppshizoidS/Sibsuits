#include "List.hpp"
#include "BaseListFunc.hpp"

int main() {

  single_linked_list<int> myList {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

  std::cout << "Forward: ";
  list_functions::printForwardRecursive<int>(myList.end());
  std::cout << std::endl;

  std::cout << "Reverse: ";
  list_functions::printReverseRecursive<int>(myList.begin());
  std::cout << std::endl;

  std::cout << "List: ";
  list_functions::printList<int>(myList);

  int checksum = list_functions::calculateChecksum<int>(myList);
  std::cout << "Checksum: " << checksum << std::endl;

  int seriesCount = list_functions::countSeries<int>(myList);
  std::cout << "Series count: " << seriesCount << std::endl;

  list_functions::removeAll<int>(myList);

  if (myList.empty()) {
    std::cout << "The list is empty after removal." << std::endl;
  }

  return 0;
}