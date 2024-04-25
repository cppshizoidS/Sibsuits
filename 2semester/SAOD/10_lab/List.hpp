//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <random>
#include "Node.hpp"

template <typename T>
class LinkedList {
 private:
  Node<T> *head;
  int sizeOfList;

 public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() { clear(); }

  // Function to print the elements of the list
  void print() {
    Node<T> *current = head;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // Function to calculate the checksum of the elements in the list
  int check_sum() {
    int sum = 0;
    Node<T> *current = head;
    while (current) {
      sum += current->data;
      current = current->next;
    }
    return sum;
  }

  // Function to count the number of series in the list
  int countSeries() {
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
  void clear() {
    while (head) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void fill_rand(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);  // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      pushFront(dis(gen));  // Assuming push is a function to add elements to
                            // some data structure
    }
  }

  void fill_inc(int size) {
    for (int i = 0; i < size; i++) {
      pushFront(i);
    }
  }

  void fill_dec(int size) {
    for (int i = size - 1; i >= 0; i--) {
      pushFront(i);
    }
  }

  // Function to print elements of the list recursively in forward order
  void printRecursiveForward(Node<T> *current) {
    if (current) {
      std::cout << current->data << " ";
      printRecursiveForward(current->next);
    }
  }

  // Function to print elements of the list recursively in reverse order
  void printRecursiveReverse(Node<T> *current) {
    if (current) {
      printRecursiveReverse(current->next);
      std::cout << current->data << " ";
    }
  }

  // Wrapper function to print elements of the list recursively in forward order
  void printRecursiveForward() {
    printRecursiveForward(head);
    std::cout << std::endl;
  }

  // Wrapper function to print elements of the list recursively in reverse order
  void printRecursiveReverse() {
    printRecursiveReverse(head);
    std::cout << std::endl;
  }

  // Function to add a new node to the front of the list
  void pushFront(T newData) { head = new Node<T>(newData, head); }

  void merge(LinkedList<T> &otherList) {
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

  void digitalSort(int maxDigits) {
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
      for (int j = 0; j < 10; j++) {
        Node<T> *bucketHead = buckets[j].head;
        while (bucketHead != nullptr) {
          pushFront(bucketHead->data);
          bucketHead = bucketHead->next;
        }
      }
      divisor *= 10;
    }
  }
};
#endif
