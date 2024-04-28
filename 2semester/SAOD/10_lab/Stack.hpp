//
// Created by cppshizoid on 4/23/24.
//

#ifndef STACK_HPP
#define STACK_HPP

#include <random>
#include <print>
#include "Node.hpp"

namespace container {

template <typename T>
class Stack
{
 private:
  int sizeOfStack;
  Node<T> *currentTop;

 public:
  [[maybe_unused]] constexpr  Stack() noexcept {
    sizeOfStack = 0;
    currentTop = nullptr;
  }

  constexpr  ~Stack() noexcept {
    while (size())
      pop();
  }

  [[maybe_unused]] constexpr void push(T element) noexcept {
    auto *node = new Node<T>(element, currentTop);
    currentTop = node;
    sizeOfStack++;
  }

  [[maybe_unused]] constexpr  void pop() noexcept
  {
    Node<T> *node = currentTop;
    currentTop = currentTop->next;
    sizeOfStack--;
    delete node;
  }

  [[maybe_unused]] constexpr  T top() noexcept
  {
    return currentTop->data;
  }

  [[maybe_unused]] constexpr int size() noexcept
  {
    return sizeOfStack;
  }

  [[maybe_unused]] constexpr  void fill_rand(int size) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99); // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      push(dis(gen)); // Assuming push is a function to add elements to some data structure
    }
  }
  [[maybe_unused]] constexpr void fill_inc(int size) noexcept
  {
    for (int i = 0; i < size; i++)
    {
      push(i);
    }
  }

  [[maybe_unused]] constexpr void fill_dec(int size) noexcept
  {
    for (int i = size - 1; i >= 0; i--)
    {
      push(i);
    }
  }

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

  [[maybe_unused]] constexpr void clear() noexcept
  {
    while (size())
      pop();
  }
};
}
#endif