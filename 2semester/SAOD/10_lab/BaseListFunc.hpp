//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_FUNCTIONS_HPP
#define LIST_FUNCTIONS_HPP

#include <print>

#include "Node.hpp"

namespace list_functions {
template <typename T>
class [[maybe_unused]] SinglyLinkedList {
 private:
  Node<T> *head;
  int sizeOfList;

 public:
  constexpr SinglyLinkedList() noexcept  {
    head = nullptr;
    sizeOfList = 0;
  }

  constexpr ~SinglyLinkedList() noexcept  { clear(); }

  constexpr bool isEmpty() noexcept  { return head == nullptr; }

  [[maybe_unused]] constexpr void insertFront(T data) noexcept  {
    auto *newNode = new Node<T>(data, nullptr);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    sizeOfList++;
  }

  [[maybe_unused]] constexpr void removeFront() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      sizeOfList--;
    }
  }

  [[maybe_unused]] constexpr T getFront() noexcept {
    if (!isEmpty()) {
      return head->data;
    }
  }

  [[maybe_unused]] constexpr int size() noexcept { return sizeOfList; }

  [[maybe_unused]] constexpr void printList() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = head;
      while (temp != nullptr) {
        std::print("{} ", temp->data);
        temp = temp->next;
      }
      std::println("\n");
    }
  }

  [[noreturn]] void clear() noexcept {
    while (!isEmpty()) removeFront();
  }
};
}  // namespace list_functions

#endif
