//
// Created by cppshizoid on 4/23/24.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <print>
#include <random>
#include "Node.hpp"

namespace container {

template <typename T>
class Queue {
 private:
  Node<T> *front;
  Node<T> *rear;
  int sizeOfQueue{};

 public:
  [[maybe_unused]] constexpr Queue() {
    front = nullptr;
    rear = nullptr;
  }

  constexpr ~Queue() {
    while (size()) pop();
  }

  [[maybe_unused]] constexpr bool isEmpty() noexcept { return front == nullptr; }

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

  [[maybe_unused]] constexpr void pop() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = front;
      front = front->next;
      sizeOfQueue--;
      delete temp;
    }
  }

  [[maybe_unused]] constexpr int peek() noexcept {
    if (!isEmpty()) {
      return front->data;
    }
  }

  [[maybe_unused]] constexpr int size() noexcept { return sizeOfQueue; }

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

  [[maybe_unused]] constexpr void fill_inc(int size) noexcept {
    for (int i = 0; i < size; i++) {
      push(i);
    }
  }

  [[maybe_unused]] constexpr void fill_dec(int size) noexcept {
    for (int i = size - 1; i >= 0; i--) {
      push(i);
    }
  }

  [[maybe_unused]] constexpr void fill_rand(int size) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);  // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      push(dis(gen));  // Assuming push is a function to add elements to some
                       // data structure
    }
  }

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

  [[maybe_unused]] constexpr void clear() noexcept {
    while (!isEmpty()) pop();
  }
};
}
#endif