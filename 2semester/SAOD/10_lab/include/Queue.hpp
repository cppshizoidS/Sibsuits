//
// Created by cppshizoid on 4/23/24.
//
// Queue.hpp
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <print>
#include <random>
#include "Node.hpp"

namespace container {

/**
 * @brief A queue data structure implementation.
 * @tparam T The type of data held in the queue.
 */
template <typename T>
class Queue {
 private:
  Node<T> *front; ///< Pointer to the front of the queue.
  Node<T> *rear; ///< Pointer to the rear of the queue.
  int sizeOfQueue{}; ///< Size of the queue.

 public:
  /**
   * @brief Constructor to initialize an empty queue.
   */
  [[maybe_unused]] constexpr Queue() {
    front = nullptr;
    rear = nullptr;
  }

  /**
   * @brief Destructor to deallocate memory.
   */
  constexpr ~Queue() {
    while (size()) pop();
  }

  /**
   * @brief Check if the queue is empty.
   * @return true if the queue is empty, false otherwise.
   */
  [[maybe_unused]] constexpr bool isEmpty() noexcept { return front == nullptr; }

  /**
   * @brief Add an element to the rear of the queue.
   * @param data The data to be added to the queue.
   */
  [[maybe_unused]] constexpr void push(T data) noexcept {
    auto *newNode = new Node<T>(data, nullptr);
    newNode->data = data;
    newNode->next = nullptr;
    sizeOfQueue++;
    if (isEmpty()) {
      front = newNode;
      rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  /**
   * @brief Remove the element from the front of the queue.
   */
  [[maybe_unused]] constexpr void pop() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = front;
      front = front->next;
      sizeOfQueue--;
      delete temp;
    }
  }

  /**
   * @brief Get the element at the front of the queue without removing it.
   * @return The element at the front of the queue.
   */
  [[maybe_unused]] constexpr int peek() noexcept {
    if (!isEmpty()) {
      return front->data;
    }
  }

  /**
   * @brief Get the size of the queue.
   * @return The size of the queue.
   */
  [[maybe_unused]] constexpr int size() noexcept { return sizeOfQueue; }

  /**
   * @brief Print all elements in the queue.
   */
  [[maybe_unused]] constexpr void printQueue() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = front;
      while (temp != nullptr) {
        std::print("{} ", temp->data);
        temp = temp->next;
      }
      std::print("\n");
    }
  }

  /**
   * @brief Fill the queue with increasing integers starting from 0.
   * @param size The number of elements to fill the queue with.
   */
  [[maybe_unused]] constexpr void fill_inc(int size) noexcept {
    for (int i = 0; i < size; i++) {
      push(i);
    }
  }

  /**
   * @brief Fill the queue with decreasing integers starting from (size - 1).
   * @param size The number of elements to fill the queue with.
   */
  [[maybe_unused]] constexpr void fill_dec(int size) noexcept {
    for (int i = size - 1; i >= 0; i--) {
      push(i);
    }
  }

  /**
   * @brief Fill the queue with random integers in the range [0, 99].
   * @param size The number of elements to fill the queue with.
   */
  [[maybe_unused]] constexpr void fill_rand(int size) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);  // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      push(dis(gen));  // Assuming push is a function to add elements to some
                       // data structure
    }
  }

  /**
   * @brief Calculate the sum of all elements in the queue.
   * @return The sum of all elements.
   */
  [[maybe_unused]] constexpr T check_sum() noexcept {
    T sum = 0;
    if (!isEmpty()) {
      Node<T> *temp = front;
      while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
      }
    }
    return sum;
  }

  /**
   * @brief Check how many increasing series are in the queue.
   * @return The number of increasing series.
   */
  [[maybe_unused]] constexpr T check_series() noexcept {
    T k = 1;
    if (!isEmpty()) {
      Node<T> *temp = front;
      while (temp->next != nullptr) {
        if (temp->data <= temp->next->data) {
          temp = temp->next;
        } else {
          k++;
          temp = temp->next;
        }
      }
    }
    return k;
  }

  /**
   * @brief Clear the queue.
   */
  [[maybe_unused]] constexpr void clear() noexcept {
    while (!isEmpty()) pop();
  }
};
}
#endif
