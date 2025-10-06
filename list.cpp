#include <iostream>
#include <iterator>
#include <list>

using namespace std;

/*
 * NOTE IMPORTANT : C++ does not have a LinkedList class like Java with index
 * access,instead it has std::list(doubly linked list)
 */

// *************************************************************************************

/* Linked List
 * LinkedList: stores Nodes in 2 parts (data + address)
 * Nodes are in non-consecutive memory locations
 * Elements are linked using pointers
 *
 *                        Singly Linked List
 *             Node               Node               Node
 *      [data | address] -> [data | address] -> [data | address]
 *
 *
 *
 *                         Doubly Linked List
 *                   Node                           Node
 *        [address | data | address] <-> [address | data | address]
 *
 * Advantages:
 *  1) Dynamic Data Structure (allocates needed memory while running)
 *  2) Insertion and Deletion of Nodes is easy. O(1)
 *  3) No/Low memory waste
 *
 * Disadvantages:
 *  1) Greater memory usage (additional pointer)
 *  2) No random access of elements (no index [i])
 *  3) Accessing / searching elements is more time consuming. O(n)
 *
 * Uses:
 *  1) Implement Stacks/Queues
 *  2) GPS Navigation
 *  3) music playlist
 *
 * Methods Available & Time Complexity:
 *
 * Constructors     list(), list(n, val)                    ||  Create Lists
 *
 * Capacity         size(), empty(), max_size()             ||  ALL O(q)
 *
 * Access           front(), back()                         ||  O(1)
 *
 * Modifiers        push_front(), push_back(),              ||  Efficient
 *                  pop_front(), pop_back(),
 *                  insert(), erase(), clear(), assign()
 *
 * Operations       remove(), remove_if()                   || Higher-level
 *                  unique(), reverse(), sort()             || Linked-list
 *                  merge(), splice()                       || Algorithms
 *
 * Iterators        begin(), end(), rbegin()                || Bidirectional
 *                  rend()
 *
 * Non-member functions     ==, <, etc                      || Compare two
 * lists
 *
 */

// *************************************************************************************

int main() {
  list<int> lst = {1, 2, 3, 4, 5};

  lst.push_front(0); // Add 0 to the fron of the list
  lst.push_back(6);  // Add 6 at the end of the list

  // [0] = 0, [1] = 1, [2] = 2, [3] = 3, [4] = 4, [5] = 5, [6] = 6

  auto it = lst.begin();
  advance(it, 3);
  lst.insert(it, 99); // Insert before 3rd element

  // [0] = 0, [1] = 1, [2] = 2, [3] = 99, [4] = 3, [5] = 4, [6] = 5, [7] = 6

  std::list<int>::iterator index = lst.begin();
  advance(index, 6);
  lst.insert(index, 4);
  lst.insert(index, 5);

  cout << "INSERT 99 BEFORE INDEX 3 & INSERT 4 BEFORE 5" << endl;

  /**
   * To understand this we need to remember that std::list stores address and
   * data, is not like a vector or array, that is contiguous. So first we need
   * to start at the beggining of the list, and use an iterator to traverse the
   * list until the end.
   *
   * auto: lets the compiler automatically deduce the variable's type (iterator
   * in this case)
   *
   * std::list<int>::iterator it = lst.begin() (otherwise)
   */
  cout << "List: ";
  for (auto it = lst.begin(); it != lst.end(); it++) {
    cout << *it << " "; // *it will get the actual value at the current address
  }
  cout << endl;

  lst.remove(4); // Remove all 4s

  cout << "-------------------------------------------" << endl; // Separator

  cout << "REVERSED LIST" << endl;

  lst.reverse(); // Reverse the list

  cout << "List: ";
  for (auto it = lst.begin(); it != lst.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "-------------------------------------------" << endl; // Separator

  cout << "LIST AFTER SORTING" << endl;

  lst.sort(); // sort ascending

  cout << "List ";
  for (int x : lst)
    cout << x << " ";
  cout << endl;

  cout << "-------------------------------------------" << endl; // Separator

  cout << "LIST AFTER REMOVING DUPLICATES" << endl;

  lst.unique(); // remove consecutive duplicates

  cout << "List: ";
  for (int x : lst)
    cout << x << " ";
  cout << endl;
}