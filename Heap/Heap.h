/** @file Heap.h  */
#ifndef _HEAP
#define _HEAP

#include "Patient.h"
#include <string>

const int MAX_ITEMS = 10;

class Heap
{
private:
    // Patient items[MAX_ITEMS];
    Patient* items;
    int itemCount = 0; 
public:
   Heap();
   bool add(int aPriority, std::string aName);
   void heapRebuild(int rootIndex);
   bool remove();
   Patient peekTop();
}; // end Heap

//#include "Heap.cpp"
#endif