//
// Created by cppshizoid on 4/23/24.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

template <typename T>
class LinkedList {
 private:
  Node<T> *head;

 public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() {
    clear();
  }

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
    std::uniform_int_distribution<int> dis(0, 99); // Range from 0 to 99

    for (int i = 0; i < size; i++) {
      pushFront(dis(gen)); // Assuming push is a function to add elements to some data structure
    }
  }

  void fill_inc(int size)
  {
    for (int i = 0; i < size; i++)
    {
      pushFront(i);
    }
  }

  void fill_dec(int size)
  {
    for (int i = size - 1; i >= 0; i--)
    {
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
  void pushFront(T newData) {
    head = new Node<T>(newData, head);
  }
};
#endif