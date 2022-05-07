/** @file Dictionary.cpp */

#include "Person.h"
#include "Dictionary.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

Dictionary::Dictionary() {
    items = new Person[MAX_ITEMS];
}

int Dictionary::getPersonPosition(int left, int right, std::string aName) {
    if (right < left)  
        return -1;  

    int mid = (left + right) / 2;  
    if (aName == items[mid].getName())  
        return mid;  

    if (aName > items[mid].getName())
        return getPersonPosition((mid + 1), right, aName);  

    return getPersonPosition(left, (mid - 1), aName);
}

Person Dictionary::getPerson(std::string aName) {
    int pos = getPersonPosition(0, itemCount, aName);

    if (pos == -1)
        throw std::invalid_argument("Does not exist in dictionary: " + aName);

    return items[pos];
}

// Insert sorted by birthday, compares year -> month -> day
bool Dictionary::insertSorted(std::string aName, int aMonth, int aDay, int aYear) {
    if (itemCount == MAX_ITEMS) {
        return false;
    }
    
    int i; 
    for (i = itemCount - 1; (i >= 0 && items[i].getName() > aName); i--) 
        items[i + 1] = items[i]; 

    items[i + 1] = Person(aName, aMonth, aDay, aYear);;
    itemCount++;
    return true;
}

bool Dictionary::remove(std::string aName) {
    // Find position of element to be deleted  
    int pos = getPersonPosition(0, itemCount, aName);  
    if (pos == -1) 
    {
        cout << "Does not exist in dictionary: " << aName << endl;
        return false;
    }  

    for (int i = pos; i < itemCount - 1; i++)  
        items[i] = items[i + 1]; 

    itemCount--;
    return true;
}

std::string Dictionary::getBirthdayByName(std::string aName) {
    int pos = getPersonPosition(0, itemCount, aName);  
    if (pos == -1)
        throw std::invalid_argument("Does not exist in dictionary: " + aName);
    return items[pos].getBirthday();
}

void Dictionary::displayAll() {
    for (int i = 0; i < itemCount; i++) {
        cout << "Name: " << items[i].getName() << ", Birthday: " << items[i].getBirthday() << endl;
    }
}

void Dictionary::displayAllInMonth(int aMonth) {
    for (int i = 0; i < itemCount; i++) {
        Person person = items[i];
        if (aMonth != person.getMonth())
            continue;
        cout << "Name: " << person.getName() << ", Birthday: " << person.getBirthday() << endl;
    }
}

void Dictionary::deallocateMemory() {
    delete[] items;
}