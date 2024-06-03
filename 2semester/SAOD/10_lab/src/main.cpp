#include "../include/List.hpp"
#include "../include/Queue.hpp"
#include "../include/Stack.hpp"

/**
 * @brief Точка входа для приложения.
 * @return 0.
 */
auto main() -> int {
  const int FILL_SIZE = 50;
  container::Stack<int> stack;
  container::Queue<int> queue;
  container::LinkedList<int> list;
  container::LinkedList<int> listForMergeSort;

  std::print("Dec stack: ");
  stack.fill_dec(FILL_SIZE);
  stack.printStack();
  stack.clear();

  std::print("Inc stack: ");
  stack.fill_inc(FILL_SIZE);
  stack.printStack();
  stack.clear();

  std::print("Rand stack: ");
  stack.fill_rand(FILL_SIZE);
  stack.printStack();

  int stacksum = stack.check_sum();
  std::print("Sum rand stack: {}\n", stacksum);
  int stackseries = stack.check_series();
  std::print("Series rand stack: {}\n", stackseries);

  std::print("\n");

  std::print("Dec queue: ");
  queue.fill_dec(FILL_SIZE);
  queue.printQueue();
  queue.clear();

  std::print("Inc queue: ");
  queue.fill_inc(FILL_SIZE);
  queue.printQueue();
  queue.clear();

  std::print("Rand queue: ");
  queue.fill_rand(FILL_SIZE);
  queue.printQueue();

  int queuesum = queue.check_sum();
  std::print("{}", "Sum rand queue:\n", queuesum, "\n");
  int queueseries = queue.check_series();
  std::print("{}", "Series rand queue:\n", queueseries, "\n");

  list.pushFront('s');
  list.pushFront(2);
  list.pushFront(2);
  list.pushFront(1);
  list.pushFront(1);
  list.pushFront(1);
  std::print("\n");

  std::print("List elements: ");
  list.print();

  std::print("Sorting list using digital sort...\n");
  list.digitalSort(0);

  std::print("List elements after sorting: ");
  list.print();

  listForMergeSort.pushFront('s');
  listForMergeSort.pushFront(2);
  listForMergeSort.pushFront(2);
  listForMergeSort.pushFront(1);
  listForMergeSort.pushFront(1);
  listForMergeSort.pushFront(1);
  std::print("\n");

  std::print("List elements: ");
  list.print();

  std::print("Sorting list using digital sort...\n");
  list.digitalSort(6);

  std::print("List elements after sorting: ");
  list.print();

  std::print("Checksum: {}\n", list.check_sum());

  std::print("Number of series: {}\n", list.countSeries());

  std::print("Printing recursively in reverse order: ");
  list.printRecursiveForward();

  std::print("Printing recursively in forward order: ");
  list.printRecursiveReverse();

  // Clear the list
  list.clear();

  std::print("Dec list: ");
  list.fill_dec(FILL_SIZE);
  list.printRecursiveForward();
  int declistsum = list.check_sum();
  std::print("Sum dec list: {}\n", declistsum);
  int declistseries = list.countSeries(); // Fixed the variable name here
  std::print("Series dec list: {}\n", declistseries);
  list.clear();

  std::print("Inc list: ");
  list.fill_inc(FILL_SIZE);
  list.printRecursiveForward();
  int inclistsum = list.check_sum();
  std::print("Sum inc list: {}\n", inclistsum);
  int inclistseries = list.countSeries(); // Fixed the variable name here
  std::print("Series inc list: {}\n", inclistseries);

  std::print("Rand list: ");
  list.fill_rand(FILL_SIZE);
  list.printRecursiveForward();

  int randlistsum = list.check_sum();
  std::print("Sum rand list: {}\n", randlistsum);
  int randlistseries = list.countSeries(); // Fixed the variable name here
  std::print("Series rand list: {}\n", randlistseries);

  // Clear the list
  list.clear();

  listForMergeSort.pushFront(1);
  listForMergeSort.pushFront(2);
  listForMergeSort.pushFront(20);
  listForMergeSort.pushFront(1);
  listForMergeSort.pushFront(1);
  listForMergeSort.pushFront(1);
  std::print("\n");

  std::print("List elements: ");
  listForMergeSort.print();

  std::print("Sorting list using merge sort...\n");
  listForMergeSort.mergeSort();

  std::print("List elements after sorting: ");
  listForMergeSort.print();

  std::print("Checksum: {}\n", list.check_sum());

  std::print("Number of series: {}\n", list.countSeries());

  std::print("Printing recursively in forward order: ");
  list.printRecursiveForward();

  std::print("Printing recursively in reverse order: ");
  list.printRecursiveReverse();

  return 0;
}
