#include <iostream>
#include <queue>

using namespace std;

// *************************************************************************************

/* Priority Queue
 * Priority Queue is a FIFO data structure that serves elements with the highest
 * priorities first before elements with the lower priority
 *
 * You can only add at the back (enqueue) and remove from the front (dequeue)
 *
 * Methods Available & Time Complexity
 *
 *      push():     Add (enqueue) element to the back         ||    O(log n)
 *      pop():      Remove (dequeue) element from the front   ||    O(log n)
 *      top():      Access element at the front               ||    O(1)
 *      empty():    Check if the queue is empty               ||    O(1)
 *      size():     Get the number of elements                ||    O(1)
 *
 * NOTE: Priority Queues do not have front(), neither back(). since data is not
 * stored in fixed ordered. It is prioritized by comparison.
 *
 */

// *************************************************************************************

int main() {

  // Priority Queue
  priority_queue<double> grades_priority;

  cout << "PRIORITY QUEUE" << endl;

  grades_priority.push(3.0);
  grades_priority.push(2.5);
  grades_priority.push(4.0);
  grades_priority.push(1.5);
  grades_priority.push(2.0);

  cout << "Size: " << grades_priority.size() << endl;

  cout << "-------------------------------------------" << endl; // Separator

  cout << "PRIORITY QUEUE INVERSED" << endl;

  // Build a min-heap with the same values
  priority_queue<double, vector<double>, greater<double>> pq;

  // Copy so we don't destroy the original set
  priority_queue<double> temp = grades_priority;

  while (!temp.empty()) {
    pq.push(temp.top()); // This just copies the values, before printing we need
                         // to copy all the queue
    temp.pop();
  }

  // Now print by popping from the min-heap: ascending order
  while (!pq.empty()) {
    cout << pq.top() << endl; // 1.5, 2, 2.5, 3, 4
    pq.pop();
  }

  cout << "-------------------------------------------" << endl; // Separator

  cout << "BACK TO DESCENDING PRIORITY QUEUE" << endl;

  while (!grades_priority.empty()) {
    cout << grades_priority.top() << endl;
    grades_priority.pop();
  }

  // Head          Tail
  // 4, 3, 2.5, 2, 1.5

  cout << "-------------------------------------------" << endl; // Separator

  // Normal Queue
  queue<double> grades; // Creates a queue of doubles

  cout << "NORMAL QUEUE" << endl;

  grades.push(3.0);
  grades.push(2.5);
  grades.push(4.0);
  grades.push(1.5);
  grades.push(2.0);

  cout << "Size: " << grades.size() << endl;

  while (!grades.empty()) {
    cout << grades.front() << endl; // This is with a normal queue
    grades.pop();                   // Removes the element from the front
  }

  // Head           Tail
  // 3, 2.5, 4, 1.5, 2
}