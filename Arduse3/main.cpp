/**********************************************************
*** NAME        :   Isaac Arduser                       ***
*** CLASS       :   CSC 300                             ***
*** ASSINGMENT  :   3                                   ***
*** DUE DATE    :   10/18/2023                          ***
*** INSTRUCTOR  :   Gamradt                             ***
***********************************************************
*** DESCRIPTION : This is the main file for Queue       ***
***********************************************************/


#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue myQueue(5); // Create a queue with a size of 5

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60);

    //View queue
    myQueue.view();
    cout << endl;

    // Dequeue an element
    Element dequeuedElement;
    myQueue.dequeue(dequeuedElement);


    // View the contents of the queue (customize as needed)
    myQueue.view();

    // Check if the queue is empty
    if (myQueue.isEmpty()) {
        cout << "Queue is empty." << endl;
    }

    // Check if the queue is full
    if (myQueue.isFull()) {
        cout << "Queue is full." << endl;
    }

    return 0;
}
