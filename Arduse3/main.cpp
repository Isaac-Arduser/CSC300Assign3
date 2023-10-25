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
    Queue q1, q2(5); // Create a queue with a size of 5

    // Enqueue elements
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q2.enqueue(99);
    q2.enqueue(100);

    //View queue
    q1.view();
    q2.view();
    cout << endl;

    // Dequeue an element
    Element dequeuedElement;
    q1.dequeue(dequeuedElement);
    q1.dequeue(dequeuedElement);
    q1.dequeue(dequeuedElement);
    q1.dequeue(dequeuedElement);



    // View the contents of the queue (customize as needed)
    q1.view();

    // Check if the queue is empty
    // if (q1.isEmpty()) {
    //     cout << "Queue is empty." << endl;
    // }

    // // Check if the queue is full
    // if (q1.isFull()) {
    //     cout << "Queue is full." << endl;
    // }

    return 0;
}
