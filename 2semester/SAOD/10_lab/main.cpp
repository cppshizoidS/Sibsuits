#include "List.hpp"
#include "Queue.hpp"
#include "Stack.hpp"


auto main() -> int {
  const int FILL_SIZE = 50;
  Stack<int> stack;
  Queue<int> queue;
  LinkedList<int> list;

  std::cout << "Dec stack: ";
  stack.fill_dec(FILL_SIZE);
  stack.printStack();
  stack.clear();

  std::cout << "Inc stack: ";
  stack.fill_inc(FILL_SIZE);
  stack.printStack();
  stack.clear();

  std::cout << "Rand stack: ";
  stack.fill_rand(FILL_SIZE);
  stack.printStack();

  int stacksum = stack.check_sum();
  std::cout << "Sum rand stack: " << stacksum << "\n";
  int stackseries = stack.check_series();
  std::cout << "Series rand stack: " << stackseries << "\n";

  std::cout << "\n";

  std::cout << "Dec queue: ";
  queue.fill_dec(FILL_SIZE);
  queue.printQueue();
  queue.clear();

  std::cout << "Inc queue: ";
  queue.fill_inc(FILL_SIZE);
  queue.printQueue();
  queue.clear();

  std::cout << "Rand queue: ";
  queue.fill_rand(FILL_SIZE);
  queue.printQueue();

  int queuesum = queue.check_sum();
  std::cout << "Sum rand queue: " << queuesum << "\n";
  int queueseries = queue.check_series();
  std::cout << "Series rand queue: " << queueseries << "\n";

  list.pushFront(3);
  list.pushFront(2);
  list.pushFront(2);
  list.pushFront(1);
  list.pushFront(1);
  list.pushFront(1);
  std::cout << "\n";

  std::cout << "List elements: ";
  list.print();

  std::cout << "Sorting list using digital sort...\n";
  list.digitalSort(3);

  std::cout << "List elements after sorting: ";
  list.print();

  std::cout << "Checksum: " << list.check_sum() << std::endl;

  std::cout << "Number of series: " << list.countSeries() << std::endl;

  std::cout << "Printing recursively in forward order: ";
  list.printRecursiveForward();

  std::cout << "Printing recursively in reverse order: ";
  list.printRecursiveReverse();

  // Clear the list
  list.clear();

  std::cout << "Dec list: ";
  list.fill_dec(FILL_SIZE);
  list.printRecursiveForward();
  int declistsum = list.check_sum();
  std::cout << "Sum dec list: " << declistsum << "\n";
  int declistseries = list.countSeries(); // Fixed the variable name here
  std::cout << "Series dec list: " << declistseries << "\n";
  list.clear();

  std::cout << "Inc list: ";
  list.fill_inc(FILL_SIZE);
  list.printRecursiveForward();
  int inclistsum = list.check_sum();
  std::cout << "Sum inc list: " << inclistsum << "\n";
  int inclistseries = list.countSeries(); // Fixed the variable name here
  std::cout << "Series inc list: " << inclistseries << "\n";

  std::cout << "Rand list: ";
  list.fill_rand(FILL_SIZE);
  list.printRecursiveForward();

  int randlistsum = list.check_sum();
  std::cout << "Sum rand list: " << randlistsum << "\n";
  int randlistseries = list.countSeries(); // Fixed the variable name here
  std::cout << "Series rand list: " << randlistseries << "\n";

  // Clear the list
  list.clear();

  return 0;
}
