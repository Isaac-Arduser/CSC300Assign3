/**********************************************************
*** NAME        :   Isaac Arduser                       ***
*** CLASS       :   CSC 300                             ***
*** ASSINGMENT  :   3                                   ***
*** DUE DATE    :   10/18/2023                          ***
*** INSTRUCTOR  :   Gamradt                             ***
***********************************************************
*** DESCRIPTION : This is the implementation for Queue  ***
***********************************************************/
#include <iostream>
#include "Queue.h"
using namespace std;


/**********************************************************************************
*** FUNCTION    : Queue::Queue(int size)                                        ***
***********************************************************************************
*** DESCRIPTION :   Constructor, initializes a new Queue with a specific size   ***
*** INPUT ARGS  :   size - integer declairing specific size of Queue            ***
*** OUTPUT ARGS :   n/a                                                         ***
*** IN/OUT ARGS :   n/a                                                         ***
*** RETURN      :   n/a                                                         ***
***********************************************************************************/
Queue::Queue(int size)
{
    QUEUE_SIZE = size;
    queueArray = new Element[size];
    head = 0;
    tail = 0;
}


/******************************************************************************************
*** FUNCTION    :   Queue::Queue(Queue &other)                                          ***
*******************************************************************************************
*** DESCRIPTION :   Copy constructor, used to create a new Queue from existing Queue    ***
*** INPUT ARGS  :   other - reference to existing Queue                                 ***
*** OUTPUT ARGS :   n/a                                                                 ***
*** IN/OUT ARGS :   n/a                                                                 ***
*** RETURN      :   n/a                                                                 ***
*******************************************************************************************/
Queue::Queue(Queue &other)
{
    QUEUE_SIZE = other.QUEUE_SIZE;
    queueArray = new Element[other.QUEUE_SIZE];
    head = other.head;
    tail = other.tail;
}

/**********************************************************************************
*** FUNCTION    : Queue::~Queue()                                               ***
***********************************************************************************
*** DESCRIPTION : Destructor, deletes dynamically allocated memory from queue   ***
*** INPUT ARGS  :   n/a                                                         ***
*** OUTPUT ARGS :   n/a                                                         ***
*** IN/OUT ARGS :   n/a                                                         ***
*** RETURN      :   n/a                                                         ***
***********************************************************************************/
Queue::~Queue()
{
    delete[] queueArray;
}

/******************************************************************
*** FUNCTION    : void Queue::enqueue(const Element item)       ***
*******************************************************************
*** DESCRIPTION : Add an element to the back of queue (tail)    ***
*** INPUT ARGS  : item - element to add                         ***
*** OUTPUT ARGS :   n/a                                         ***
*** IN/OUT ARGS :   n/a                                         ***
*** RETURN      :   n/a                                         ***
*******************************************************************/
void Queue::enqueue(const Element item)
{
    if (!isFull())
    {
        queueArray[tail] = item;
        tail = (tail + 1) % QUEUE_SIZE;
    }
    else
    {
        cout << "Error 100: Queue is full" << endl;
    }
}

/*************************************************************
*** FUNCTION    : void Queue::dequeue(Element &item)
**************************************************************
*** DESCRIPTION : Removes an element from the front of Queue
*** INPUT ARGS  : item - element to remove
*** OUTPUT ARGS : n/a
*** IN/OUT ARGS : n/a
*** RETURN      : n/a
*************************************************************/
void Queue::dequeue(Element &item)
{
    if (!isEmpty())
    {
        item = queueArray[head];
        head = (head + 1) % QUEUE_SIZE;
    }
    else
    {
        cout << "Error 101: Queue is empty" << endl;
    }
}

/**************************************************************************
*** FUNCTION    : void Queue::view()                                    ***
***************************************************************************
*** DESCRIPTION : Loops through the Queue and allows you to view it     ***
*** INPUT ARGS  : n/a                                                   ***
*** OUTPUT ARGS : n/a                                                   ***
*** IN/OUT ARGS : n/a                                                   ***
*** RETURN      : n/a                                                   ***
***************************************************************************/
void Queue::view()
{
    for(int i = head; i != tail; i = (i +1) % QUEUE_SIZE)
    {
       cout << queueArray[i] << endl;
    }
}

/******************************************************
*** FUNCTION    : bool Queue::isEmpty() const       ***
*******************************************************
*** DESCRIPTION : Checks if queue is empty          ***
*** INPUT ARGS  : n/a                               ***
*** OUTPUT ARGS : n/a                               ***
*** IN/OUT ARGS : n/a                               ***
*** RETURN      : True if empty, else False         ***
*******************************************************/
bool Queue::isEmpty() const
{
    return head == tail;
}

/**************************************************
*** FUNCTION    : bool Queue::isFull() const    ***
***************************************************
*** DESCRIPTION : Checks if queue is full       ***
*** INPUT ARGS  : n/a                           ***
*** OUTPUT ARGS : n/a                           ***
*** IN/OUT ARGS : n/a                           ***
*** RETURN      : True if full, else false      ***
***************************************************/
bool Queue::isFull() const
{
    return (tail + 1) % QUEUE_SIZE == head;
}