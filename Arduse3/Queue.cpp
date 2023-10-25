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
Queue::Queue(int size) : QUEUE_SIZE(size), head(-1), tail(-1)
{
    queueArray = new (nothrow) Element[QUEUE_SIZE];
    if (!queueArray)
    { 
        cout << " Memeory failed";
        exit(1);
    }
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
Queue::Queue(Queue &other) : QUEUE_SIZE(other.QUEUE_SIZE), head(-1), tail(-1)
{
    queueArray = new Element[QUEUE_SIZE];
    Queue tempQueue(QUEUE_SIZE);

    for (short i = other.head; i != other.tail; i = (i + 1) % other.QUEUE_SIZE)
    {
        Element QueueElement = other.queueArray[i];
        tempQueue.enqueue(QueueElement);
    }
    
    for (short i = tempQueue.head; i != tempQueue.tail; i = (i + 1) % tempQueue.QUEUE_SIZE)
    {
        Element QueueElement = tempQueue.queueArray[i];
        enqueue(QueueElement);
    }
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
    cout << "HEAD -> ";
    
    for(int i = head; i != tail; i = (i +1) % QUEUE_SIZE)
    {
       cout << queueArray[i] << " -> ";
    }

    cout << "TAIL" << endl;
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