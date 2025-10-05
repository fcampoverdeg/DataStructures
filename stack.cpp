#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*  STACK
 * Stack is a LIFO data strucure, imagine like stacking book on top of each other.
 * To access the very first data we need to remove all the previous ones
 * 
 *  Methods Available & Time Complexity
 * 
 *      push(): Pushes into Stack || O(1)
 *      pop(): Removes top element (no return value) || O(1)
 *      top(): Returns a reference to the top element || O(1)
 *      empty(): Returns true if stack is empty || O(1)
 *      size(): Returns the number of elements || O(1)
 * 
 * NOTE: All main stack operations work on the top element, so they take constant time.
 * 
 * 
 */

int main() {
    stack<string> programmingLanguages; // Creates "Stack" structure

    // Add elements to the stack                    (Top)------------(bottom) (vertical)
    programmingLanguages.push("C++");           // C++
    programmingLanguages.push("Java");          // Java - C++
    programmingLanguages.push("Python");        // Python - Java - C++

    // Access the top element
    cout << "Top element: " << programmingLanguages.top() << endl;

    // Search stack with copy (does not lose the data from the stack)
    stack<string> copy = programmingLanguages; // Copies original stack to copy and searches in copy

    int index = 0; // Creates index
    bool found = false; // Creates flag to stop while loop

    while (!copy.empty()) {

        // If item found get the index and break
        if (copy.top() == "C++") {
            cout << "C++ found at index: " << index << endl;
            found = true;
            break;
        }
        
        copy.pop(); // Pops from othe stack 
        index++; // Increases index every time it iterates through an item
    }

    if (!found) cout << "C++ was not found in the Stack." << endl;


    // // Search for C++ (It Pops each element until it finds the item)
    // for (int index = 0; !programmingLanguages.empty(); index++) {
    //     if (programmingLanguages.top() == "C++") {
    //         cout << "C++ found at index: " << index << endl;
    //         break;
    //     }   
    //     programmingLanguages.pop();
    // }


    // Remove elements from the stack and print them
    while(!programmingLanguages.empty()) {
        cout << "Popping: " << programmingLanguages.top() << endl;
        programmingLanguages.pop(); // Removing the top element
    }

    // Check if the stack is empty
    if (programmingLanguages.empty()) {
        cout << "Stack is now empty" << endl;
    }

    return 0;
}