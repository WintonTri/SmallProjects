#include "Queue.h"
#include <exception>
#include <iostream>
#include <list>
#include <string>
using namespace std;

bool Queue::isEmpty() {
    return front == back;
}

bool Queue::isFull() {
    return front == (back+1) % (MAX_QUEUE+1);
}

bool Queue::enqueue(char newEntry) {
    if (isFull()) {
        cout << "Could not enqueue char: " << newEntry << " because queue is full!" << endl;
        return false;
    }

    back = (back + 1) % MAX_QUEUE;

    entries[back] = newEntry;

    return true;
}

bool Queue::dequeue() {
    if (isEmpty()) {
        return false;
    }

    front = (front + 1) % MAX_QUEUE;

    return true;
}

char Queue::peekFront() {
    return entries[front];
}



