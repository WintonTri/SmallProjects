/** @file Person.h  */
#ifndef _PERSON
#define _PERSON

#include <string>

class Person
{
private:
    std::string name;
    int month, day, year;    
public:
    Person();
    Person(std::string aName, int month, int day, int year);    
    std::string getName() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    std::string getBirthday() const;
}; // end Person

//#include "Person.cpp"
#endif