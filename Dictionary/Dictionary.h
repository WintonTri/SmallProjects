/** @file Dictionary.h  */
#ifndef _DICTIONARY
#define _DICTIONARY

#include "Person.h"
#include <string>

const int MAX_ITEMS = 10;

class Dictionary
{
private:
    // Patient items[MAX_ITEMS];
    Person* items;
    int itemCount = 0; 
public:
   Dictionary();
   int getPersonPosition(int left, int right, std::string aName);
   Person getPerson(std::string aName);
   bool insertSorted(std::string aName, int aMonth, int aDay, int aYear);
   bool remove(std::string aName);  
   std::string getBirthdayByName(std::string aName);
   void displayAll();
   void displayAllInMonth(int aMonth);

   void deallocateMemory();
}; // end Heap

//#include "Heap.cpp"
#endif