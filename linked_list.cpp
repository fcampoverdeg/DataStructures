#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

/* LinkedList
 * Implementation of a LinkedList in C++.
 *
 * Methods Available & Time Complexity
 *
 *  push_front():       add at the beggining                ||      O(1)
 *  push_back():        add at the end                      ||      O(n)
 *  insert_after():     Insert after a given node           ||      O(n)
 *  pop_front():        Remove the first node               ||      O(1)
 *  remove(value):      Remove a node with given value      ||      O(n)
 *  print():            Print all elements                  ||      O(n)
 */

/* Node Structure
 * Each node stores data and a pointer with the address to the next pointer
 *
 *           Node
 *      [data | address]
 *
 */
template <typename T> struct Node {
  T data;                                   // Data
  Node *next;                               // Pointer
  Node(T val) : data(val), next(nullptr) {} // Structure of Node
};

/* LinkedList Data Structure
 * A LinkedList is formed by a group of Nodes that are pointing to each other.
 *
 *            Node                 Node               Node
 *      [data | address] -> [data | address] -> [data | address]
 *
 */
template <typename T> struct LinkedList {
private:
  Node<T> *head; // Pointer to the head of the list
  Node<T> *tail; // Pointer to the tail of the list

public:
  LinkedList() : head(nullptr), tail(nullptr) {}

  ~LinkedList() {
    // TODO: clear();
  }

  // Add element at front
  void push_front(T val) {

    Node<T> *newNode = new Node<T>(val); // Dynamically allocates a node heap
    newNode->next = head; // Link new node in fornt of current head
    head = newNode;       // Advance the head to the new Node

    /*
     * empty-list edge case: In empty list head, tail == nullptr
     * after inserting the first node head -> node, tail -> node (only 1 node)
     *  If the list wasn't empty, tail stays unchanged.
     */
    if (tail == nullptr)
      tail = head;
  }

  // Add element at the end
  void push_back(T val) {
    Node<T> *newNode = new Node<T>(val);

    if (tail == nullptr) {
      tail = head = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
};
