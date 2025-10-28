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

  ~LinkedList() { clear(); }

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

  // Add element at back
  void push_back(T val) {
    Node<T> *newNode = new Node<T>(val);

    /**
     *If list was empty, head, tail and newNode should be the same. (nullptr)
     otherwise, we update the pointer of the tail pointing from nullptr to the
     actual new node.
     */
    if (tail == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Remove first element
  void pop_front() {
    if (head == nullptr) {
      return; // If list is empty, nothing to do
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;

    // If list empty, tail has to be empty too
    if (head == nullptr) {
      tail = nullptr;
    }
  }

  // Remove first node with given value
  void remove(T val) {
    if (head == nullptr) {
      return;
    }

    if (head->data == val) {
      pop_front();
      return;
    }

    Node<T> *current = head;
    while (current->next != nullptr && current->next->data != val) {
      current = current->next;
    }

    if (current->next != nullptr) {
      Node<T> *temp = current->next;
      current->next = temp->next;

      if (temp == tail) {
        tail = current;
      }

      delete temp;
    }
  }

  void print() const {
    Node<T> *current = head;

    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  // Clear List
  void clear() {
    while (head != nullptr) {
      pop_front();
    }
  }
};

// We need a main in a code so it can run.
int main() {
  LinkedList<int> list;

  list.push_front(10); // list: 10
  list.push_back(20);  // list: 10 -> 20
  list.push_front(5);  // list: 5 -> 10 -> 20

  list.print();    // expected: 5 10 20
  list.remove(10); // list: 5 -> 20
  list.print();    // expected: 5 20

  list.pop_front(); // list: 20
  list.print();     // expected: 20
}
