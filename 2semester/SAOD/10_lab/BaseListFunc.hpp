//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_FUNCTIONS_HPP
#define LIST_FUNCTIONS_HPP

#include <iostream>

#include "List.hpp"
#include "Node.hpp"

namespace list_functions {
template <typename T>
class SinglyLinkedList {
 private:
  Node<T> *head;
  int sizeOfList;

 public:
  SinglyLinkedList() {
    head = nullptr;
    sizeOfList = 0;
  }

  ~SinglyLinkedList() { clear(); }

  bool isEmpty() { return head == nullptr; }

  void insertFront(T data) {
    Node<T> *newNode = new Node<T>(data, nullptr);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    sizeOfList++;
  }

  void removeFront() {
    if (!isEmpty()) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      sizeOfList--;
    }
  }

  T getFront() {
    if (!isEmpty()) {
      return head->data;
    }
  }

  int size() { return sizeOfList; }

  void printList() {
    if (!isEmpty()) {
      Node<T> *temp = head;
      while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << "\n";
    }
  }

  void clear() {
    while (!isEmpty()) removeFront();
  }
};
}

#endif
