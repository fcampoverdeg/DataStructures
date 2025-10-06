#include <iostream>
#include <queue>
#include <string>

using namespace std;


// *************************************************************************************

/* Queue
 * Queue is a FIFO data structure, think of a line of people.
 * A collection designed for holding elements prior to processing
 * 
 * You can only add at the back (enqueue) and remove from the front (dequeue)
 * 
 * Methods Available & Time Complexity
 *  
 *      push(): Add (enqueue) element to the back || O(1)
 *      pop(): Remove (dequeue) element from the front || O(1)
 *      front(): Access element at the front || O(1)
 *      back(): Access element at the back || O(1)
 *      empty(): Check if the queue is empty || O(1)
 *      size(): Get the number of elements || O(1)
 * 
 */

// *************************************************************************************

int main() {

    queue<string> favoriteGames; // Creates a Queue structure

    // Enqueue                                 (Front)------------------------(back) (Line)
    favoriteGames.push("Minecraft");     // Minecraft
    favoriteGames.push("NFS");           // Minecraft - NFS
    favoriteGames.push("LN");            // Minecraft - NFS - LN
    favoriteGames.push("Cuphead");       // Minecraft - NFS - LN - Cuphead

    // Get the front of the queue
    cout << "Front of the queue: " << favoriteGames.front() << endl;

    // Get the back of the queue
    cout << "Back of the queue: " << favoriteGames.back() << endl;

    // Size of queue
    cout << "The size of the queue is: " << favoriteGames.size() << endl;

    while (!favoriteGames.empty()) {
        string popped_game = favoriteGames.front(); // We use Front instead of pop because pop() does not return the item that was removed
        cout << "Game popped: " << popped_game << endl;
        favoriteGames.pop();    // Pops from the front
    }

    // Check if queue is empty
    if (favoriteGames.empty()) cout << "The Queue is empty" << endl;

    // Size of queue
    cout << "The size of the queue is: " << favoriteGames.size() << endl;
    


    return 0;
}