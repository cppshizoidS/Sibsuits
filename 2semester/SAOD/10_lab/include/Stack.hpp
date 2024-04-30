//
// Created by cppshizoid on 4/23/24.
//
// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

#include <random>
#include <print>
#include "Node.hpp"

namespace container {

// Iterator for Stack class (forward iteration)
template <typename T>
class StackIterator {
 private:
  Node<T>* currentNode;

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T&;

  explicit StackIterator(Node<T>* node) : currentNode(node) {}

  StackIterator& operator++() {
    currentNode = currentNode->next;
    return *this;
  }

  StackIterator operator++(int) {
    StackIterator temp = *this;
    ++(*this);
    return temp;
  }

  reference operator*() const {
    return currentNode->data;
  }

  pointer operator->() const {
    return &(currentNode->data);
  }

  bool operator==(const StackIterator& other) const {
    return currentNode == other.currentNode;
  }

  bool operator!=(const StackIterator& other) const {
    return *this != other;
  }
};

// Iterator for Stack class (reverse iteration)
template <typename T>
class StackReverseIterator {
 private:
  Node<T>* currentNode;

 public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T&;

  explicit StackReverseIterator(Node<T>* node) : currentNode(node) {}

  StackReverseIterator& operator++() {
    currentNode = currentNode->prev;
    return *this;
  }

  StackReverseIterator operator++(int) {
    StackReverseIterator temp = *this;
    ++(*this);
    return temp;
  }

  reference operator*() const {
    return currentNode->data;
  }

  pointer operator->() const {
    return &(currentNode->data);
  }

  bool operator==(const StackReverseIterator& other) const {
    return currentNode == other.currentNode;
  }

  bool operator!=(const StackReverseIterator& other) const {
    return *this != other;
  }
};

/**
 * @brief A stack data structure implementation.
 *
 * This class implements a stack data structure using a linked list.
 * It supports common stack operations such as push, pop, top, and size.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack
{
 private:
  int sizeOfStack; /**< The size of the stack. */
  Node<T> *currentTop; /**< Pointer to the top node of the stack. */

 public:
  /**
   * @brief Default constructor.
   *
   * Initializes an empty stack.
   */
  [[maybe_unused]] constexpr  Stack() noexcept {
    sizeOfStack = 0;
    currentTop = nullptr;
  }
  /**
   * @brief Destructor.
   *
   * Clears the stack by popping all elements.
   */
  constexpr  ~Stack() noexcept {
    while (size())
      pop();
  }
  /**
   * @brief Pushes an element onto the stack.
   *
   * @param element The element to be pushed onto the stack.
   */
  [[maybe_unused]] constexpr void push(T element) noexcept {
    auto *node = new Node<T>(element, currentTop);
    currentTop = node;
    sizeOfStack++;
  }
  /**
   * @brief Removes the top element from the stack.
   */
  [[maybe_unused]] constexpr  void pop() noexcept
  {
    Node<T> *node = currentTop;
    currentTop = currentTop->next;
    sizeOfStack--;
    delete node;
  }
  /**
   * @brief Returns the top element of the stack.
   *
   * @return The top element of the stack.
   */
  [[maybe_unused]] constexpr  T top() noexcept
  {
    return currentTop->data;
  }
  /**
   * @brief Returns the size of the stack.
   *
   * @return The size of the stack.
   */
  [[maybe_unused]] constexpr int size() noexcept
  {
    return sizeOfStack;
  }
  /**
   * @brief Fills the stack with random elements.
   *
   * @param size The number of elements to generate and push onto the stack.
   */
  [[maybe_unused]] constexpr  void fill_rand(int size) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99); // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      push(dis(gen)); // Assuming push is a function to add elements to some data structure
    }
  }

  /**
   * @brief Fills the stack with increasing series of elements.
   *
   * @param size The number of elements to generate and push onto the stack.
   */
  [[maybe_unused]] constexpr void fill_inc(int size) noexcept
  {
    for (int i = 0; i < size; i++)
    {
      push(i);
    }
  }
  /**
   * @brief Fills the stack with decreasing series of elements.
   *
   * @param size The number of elements to generate and push onto the stack.
   */
  [[maybe_unused]] constexpr void fill_dec(int size) noexcept
  {
    for (int i = size - 1; i >= 0; i--)
    {
      push(i);
    }
  }
  /**
   * @brief Prints the elements of the stack.
   */
  [[maybe_unused]] constexpr void printStack() noexcept
  {
    Node<T> *currentNode = currentTop;
    while (currentNode != nullptr)
    {
      std::print("{} ", currentNode->data);
      currentNode = currentNode->next;
    }
    std::print("\n");
  }
  /**
   * @brief Computes the sum of all elements in the stack.
   *
   * @return The sum of all elements in the stack.
   */
  [[maybe_unused]] constexpr T check_sum() noexcept
  {
    Node<T> *currentNode = currentTop;
    T sum = 0;
    while (currentNode != nullptr)
    {
      sum += currentNode->data;
      currentNode = currentNode->next;
    }
    return sum;
  }
  /**
   * @brief Computes the length of the longest increasing series in the stack.
   *
   * @return The length of the longest increasing series in the stack.
   */
  [[maybe_unused]] constexpr T check_series() noexcept
  {
    T k = 1;
    Node<T> *currentNode = currentTop;
    while (currentNode != nullptr && currentNode->next != nullptr)
    {
      if (currentNode->data < currentNode->next->data)
      {
        k++;
        currentNode = currentNode->next;
      }
      else
      {
        currentNode = currentNode->next;
      }
    }

    return k;
  }
  /**
   * @brief Clears the stack by popping all elements.
   */
  [[maybe_unused]] constexpr void clear() noexcept
  {
    while (size())
      pop();
  }
};
}
#endif