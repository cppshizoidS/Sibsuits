//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_FUNCTIONS_HPP
#define LIST_FUNCTIONS_HPP

#include <print>

#include "Node.hpp"

namespace list_functions {

/**
 * @brief A singly linked list implementation.
 *
 * @tparam T The type of data stored in the list.
 */
template <typename T>
class [[maybe_unused]] SinglyLinkedList {
 private:
  Node<T> *head; /**< Pointer to the head of the list. */
  int sizeOfList; /**< The size of the list. */

 public:
  /**
   * @brief Constructs a new Singly Linked List object.
   */
  constexpr SinglyLinkedList() noexcept  {
    head = nullptr;
    sizeOfList = 0;
  }

  /**
   * @brief Destroys the Singly Linked List object and deallocates memory.
   */
  constexpr ~SinglyLinkedList() noexcept  { clear(); }

  /**
   * @brief Checks if the list is empty.
   *
   * @return true if the list is empty, false otherwise.
   */
  constexpr bool isEmpty() noexcept  { return head == nullptr; }

  /**
   * @brief Inserts an element at the front of the list.
   *
   * @param data The data to be inserted.
   */
  [[maybe_unused]] constexpr void insertFront(T data) noexcept  {
    auto *newNode = new Node<T>(data, nullptr);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    sizeOfList++;
  }

  /**
   * @brief Removes the element at the front of the list.
   */
  [[maybe_unused]] constexpr void removeFront() noexcept {
    if (!isEmpty()) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      sizeOfList--;
    }
  }

  /**
   * @brief Gets the data of the element at the front of the list.
   *
   * @return The data of the element at the front.
   */
  [[maybe_unused]] constexpr T getFront() noexcept {
    if (!isEmpty()) {
      return head->data;
    }
  }

  /**
   * @brief Gets the size of the list.
   *
   * @return The size of the list.
   */
  [[maybe_unused]] constexpr int size() noexcept { return sizeOfList; }

  /**
   * @brief Prints the elements of the list.
   */
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

  /**
   * @brief Clears the list by removing all elements.
   */
  [[noreturn]] void clear() noexcept {
    while (!isEmpty()) removeFront();
  }
};
}  // namespace list_functions

#endif
