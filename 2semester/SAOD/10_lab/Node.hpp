//
// Created by cppshizoid on 4/23/24.
//

#ifndef NODE_HPP
#define NODE_HPP


template <typename T>
struct Node {
  T data;
  Node<T> *next;

  Node(T newData, Node<T> *nextNode) {
    data = newData;
    next = nextNode;
  }
};
#endif  // INC_10_LAB_NODE_HPP
