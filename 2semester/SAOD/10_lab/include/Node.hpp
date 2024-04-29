//
// Created by cppshizoid on 4/23/24.
//
// Node.hpp
#ifndef NODE_HPP
#define NODE_HPP

/**
 * @brief A template struct representing a node in a linked list.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
struct Node {
  T data; ///< The data stored in the node.
  Node<T> *next; ///< Pointer to the next node in the linked list.
  /**
   * @brief Constructor to initialize a node with data and a pointer to the next node.
   *
   * @param newData The data to be stored in the node.
   * @param nextNode Pointer to the next node in the linked list.
   */
  Node(T newData, Node<T> *nextNode) {
    data = newData;
    next = nextNode;
  }
};
#endif  // NODE_HPP
