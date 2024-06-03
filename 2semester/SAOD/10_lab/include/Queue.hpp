//
// Created by cppshizoid on 4/23/24.
//
// Queue.hpp
#ifndef Queue_HPP
#define Queue_HPP

#include <random>
#include <print>
#include <iostream>
#include "Node.hpp"

namespace container {

// Iterator for Queue class (forward iteration)
template <typename T>
class QueueIterator {
 private:
  Node<T>* currentNode;

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T&;

  explicit QueueIterator(Node<T>* node) : currentNode(node) {}

  QueueIterator& operator++() {
    currentNode = currentNode->next;
    return *this;
  }

  QueueIterator operator++(int) {
    QueueIterator temp = *this;
    ++(*this);
    return temp;
  }

  reference operator*() const {
    return currentNode->data;
  }

  pointer operator->() const {
    return &(currentNode->data);
  }

  bool operator==(const QueueIterator& other) const {
    return currentNode == other.currentNode;
  }

  bool operator!=(const QueueIterator& other) const {
    return !(*this == other);
  }
};

// Iterator for Queue class (reverse iteration)
template <typename T>
class QueueReverseIterator {
 private:
  Node<T>* currentNode;

 public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T&;

  explicit QueueReverseIterator(Node<T>* node) : currentNode(node) {}

  QueueReverseIterator& operator++() {
    currentNode = currentNode->prev;
    return *this;
  }

  QueueReverseIterator operator++(int) {
    QueueReverseIterator temp = *this;
    ++(*this);
    return temp;
  }

  reference operator*() const {
    return currentNode->data;
  }

  pointer operator->() const {
    return &(currentNode->data);
  }

  bool operator==(const QueueReverseIterator& other) const {
    return currentNode == other.currentNode;
  }

  bool operator!=(const QueueReverseIterator& other) const {
    return *this != other;
  }
};

/**
 * @brief A Queue data structure implementation.
 *
 * This class implements a Queue data structure using a linked list.
 * It supports common Queue operations such as push, pop, top, and size.
 *
 * @tparam T The type of elements stored in the Queue.
 */
template <typename T>
class Queue
{
 private:
  int sizeOfQueue; /**< The size of the Queue. */
  Node<T> *currentTop; /**< Pointer to the top node of the Queue. */

 public:
  /**
   * @brief Default constructor.
   *
   * Initializes an empty Queue.
   */
  [[maybe_unused]] constexpr  Queue() noexcept {
    sizeOfQueue = 0;
    currentTop = nullptr;
  }
  /**
   * @brief Destructor.
   *
   * Clears the Queue by popping all elements.
   */
  constexpr  ~Queue() noexcept {
    while (size())
      pop();
  }
  /**
   * @brief Pushes an element onto the Queue.
   *
   * @param element The element to be pushed onto the Queue.
   */
  [[maybe_unused]] constexpr void push(T element) noexcept {
    auto *node = new Node<T>(element, currentTop);
    currentTop = node;
    sizeOfQueue++;
  }
  /**
   * @brief Removes the top element from the Queue.
   */
  [[maybe_unused]] constexpr  void pop() noexcept
  {
    Node<T> *node = currentTop;
    currentTop = currentTop->next;
    sizeOfQueue--;
    delete node;
  }
  /**
   * @brief Returns the top element of the Queue.
   *
   * @return The top element of the Queue.
   */
  [[maybe_unused]] constexpr  T top() noexcept
  {
    return currentTop->data;
  }
  /**
   * @brief Returns the size of the Queue.
   *
   * @return The size of the Queue.
   */
  [[maybe_unused]] constexpr int size() noexcept
  {
    return sizeOfQueue;
  }
  /**
   * @brief Fills the Queue with random elements.
   *
   * @param size The number of elements to generate and push onto the Queue.
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
   * @brief Fills the Queue with increasing series of elements.
   *
   * @param size The number of elements to generate and push onto the Queue.
   */
  [[maybe_unused]] constexpr void fill_inc(int size) noexcept
  {
    for (int i = 0; i < size; i++)
    {
      push(i);
    }
  }
  /**
   * @brief Fills the Queue with decreasing series of elements.
   *
   * @param size The number of elements to generate and push onto the Queue.
   */
  [[maybe_unused]] constexpr void fill_dec(int size) noexcept
  {
    for (int i = size - 1; i >= 0; i--)
    {
      push(i);
    }
  }
  /**
   * @brief Prints the elements of the Queue.
   */
  [[maybe_unused]] constexpr void printQueue() noexcept
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
   * @brief Computes the sum of all elements in the Queue.
   *
   * @return The sum of all elements in the Queue.
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
   * @brief Computes the length of the longest increasing series in the Queue.
   *
   * @return The length of the longest increasing series in the Queue.
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
   * @brief Clears the Queue by popping all elements.
   */
  [[maybe_unused]] constexpr void clear() noexcept
  {
    while (size())
      pop();
  }
};
}
#endif