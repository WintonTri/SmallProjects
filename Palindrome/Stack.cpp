#include "Stack.h"
#include <exception>
#include <iostream>
#include <list>
#include <string>
using namespace std;


Stack::Stack()              
{
} // end constructor

void Stack::push(char c) {
    arr[arrSize] = c;
    arrSize++;
}

int Stack::getArrSize() {
    return arrSize;
}

char Stack::getCharAt(int pos) {
    return arr[pos];
}

char Stack::peek() {
    if (arrSize == 0)
        throw("Indexing error occured!");
    return arr[arrSize - 1];
}

bool Stack::isEmpty() {
    return arrSize == 0;
}

void Stack::print() {
    cout << arr << endl;
}

void Stack::pop() {
    arr[arrSize - 1] = '\0';
    arrSize--;
}

