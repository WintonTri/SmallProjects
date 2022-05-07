/** @file Stack.h */
#ifndef _STACK
#define _STACK

class Stack
{
private:
   char* arr = new char[100];
   int arrSize;
public:
   Stack();
   void push(char c);
   int getArrSize();
   char getCharAt(int pos);
   char peek();
   bool isEmpty();
   void print();
   void pop();

}; // end Stack

//#include "Stack.cpp"
#endif