/** @file Queue.h */
#ifndef _QUEUE
#define _QUEUE

const int MAX_QUEUE = 10;

class Queue
{
private:
    char entries[MAX_QUEUE];
    int front;
    int back;
public:
   Queue()
    { front = 0; back = MAX_QUEUE-1; };
   bool isEmpty();
   bool isFull();
   bool enqueue(char c);
   bool dequeue();
   char peekFront();
   
}; // end Queue

//#include "Queue.cpp"
#endif