/**********************************************************
*** NAME        :   Isaac Arduser                       ***
*** CLASS       :   CSC 300                             ***
*** ASSINGMENT  :   3                                   ***
*** DUE DATE    :   10/18/2023                          ***
*** INSTRUCTOR  :   Gamradt                             ***
***********************************************************
*** DESCRIPTION : This is the header file for Queue     ***
***********************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

typedef int Element;
typedef Element *ElementPtr;

class Queue 
{
    public:
        explicit Queue (int size = 3);           // replace ... with required arguments
        Queue ( Queue &other);              // reuse enqueue & dequeue
        ~Queue();                           // reuse dequque
        void enqueue (const Element item);  // inserts a new element to the tail of the queue
        void dequeue (Element &item);       // removes an existing element from the dead of the queue
        void view();                        // reuse enqueue & dequeue
        

    private:
        const u_short QUEUE_SIZE;                     // requries initialization
        ElementPtr queueArray;
        short head, tail;
        bool isEmpty() const;
        bool isFull() const;
        
};

#endif
