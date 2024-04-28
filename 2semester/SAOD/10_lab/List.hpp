//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <random>
#include <print> // Add this line for C++23 std::print
#include "Node.hpp"

namespace container {

template <typename T>
class LinkedList {
 private:
  Node<T> *head;
  [[maybe_unused]] int sizeOfList{};

 public:
  constexpr LinkedList() : head(nullptr) {}

  constexpr ~LinkedList() { clear(); }

  // Function to print the elements of the list
  [[maybe_unused]] constexpr void print() noexcept {
    Node<T> *current = head;
    while (current) {
      std::print("{} ", current->data);  // Updated this line
      current = current->next;
    }
    std::print("\n");  // Updated this line
  }

  // Function to calculate the checksum of the elements in the list
  [[maybe_unused]] constexpr int check_sum() noexcept {
    int sum = 0;
    Node<T> *current = head;
    while (current) {
      sum += current->data;
      current = current->next;
    }
    return sum;
  }

  // Function to count the number of series in the list
  [[maybe_unused]] constexpr int countSeries() noexcept {
    int seriesCount = 0;
    Node<T> *current = head;
    while (current) {
      Node<T> *nextNode = current->next;
      while (nextNode && nextNode->data == current->data) {
        nextNode = nextNode->next;
      }
      if (nextNode != current->next) {
        seriesCount++;
      }
      current = nextNode;
    }
    return seriesCount;
  }

  // Function to delete all elements from the list
  [[maybe_unused]] constexpr void clear() noexcept {
    while (head) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }

  [[maybe_unused]] constexpr void fill_rand(int size) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);  // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      pushFront(dis(gen));  // Assuming push is a function to add elements to
                            // some data structure
    }
  }

  [[maybe_unused]] constexpr void fill_inc(int size) noexcept {
    for (int i = 0; i < size; i++) {
      pushFront(i);
    }
  }

  [[maybe_unused]] constexpr void fill_dec(int size) noexcept {
    for (int i = size - 1; i >= 0; i--) {
      pushFront(i);
    }
  }

  // Function to print elements of the list recursively in forward order
  [[maybe_unused]] constexpr void printRecursiveForward(Node<T> *current) noexcept {
    if (current) {
      std::print("{} ", current->data);  // Updated this line
      printRecursiveForward(current->next);
    }
  }

  // Function to print elements of the list recursively in reverse order
  [[maybe_unused]] constexpr void printRecursiveReverse(Node<T> *current) noexcept {
    if (current) {
      printRecursiveReverse(current->next);
      std::print("{} ", current->data);  // Updated this line
    }
  }

  // Wrapper function to print elements of the list recursively in forward order
  [[maybe_unused]] constexpr void printRecursiveForward() noexcept {
    printRecursiveForward(head);
    std::print("\n");  // Updated this line
  }

  // Wrapper function to print elements of the list recursively in reverse order
  [[maybe_unused]] constexpr void printRecursiveReverse() noexcept {
    printRecursiveReverse(head);
    std::print("\n");  // Updated this line
  }

  // Function to add a new node to the front of the list
  [[maybe_unused]] constexpr void pushFront(T newData) noexcept { head = new Node<T>(newData, head); }

  [[maybe_unused]] constexpr void merge(LinkedList<T> &otherList) noexcept {
    Node<T> *temp1 = head;
    Node<T> *temp2 = otherList.head;
    LinkedList<T> mergedList;

    while (temp1 != nullptr && temp2 != nullptr) {
      if (temp1->data < temp2->data) {
        mergedList.pushFront(temp1->data);
        temp1 = temp1->next;
      } else {
        mergedList.pushFront(temp2->data);
        temp2 = temp2->next;
      }
    }

    while (temp1 != nullptr) {
      mergedList.pushFront(temp1->data);
      temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
      mergedList.pushFront(temp2->data);
      temp2 = temp2->next;
    }

    head = mergedList.head;
    sizeOfList = mergedList.size();
  }

  [[maybe_unused]] constexpr void digitalSort(int maxDigits) noexcept {
    LinkedList<T> buckets[10];
    int divisor = 1;
    int digit;

    for (int i = 0; i < maxDigits; i++) {
      Node<T> *temp = head;
      while (temp != nullptr) {
        digit = (temp->data / divisor) % 10;
        buckets[digit].pushFront(temp->data);
        temp = temp->next;
      }

      head = nullptr;
      for (auto &bucket : buckets) {
        Node<T> *bucketHead = bucket.head;
        while (bucketHead != nullptr) {
          pushFront(bucketHead->data);
          bucketHead = bucketHead->next;
        }
      }
      divisor *= 10;
    }
  }
};
}
#endif
