/** @file Person.cpp */

#include "Person.h"
#include <string>

Person::Person() {
}

Person::Person(std::string aName, int aMonth, int aDay, int aYear) {    
    name = aName;
    month = aMonth;
    day = aDay;
    year = aYear;
}

std::string Person::getName() const {
    return name;
}

int Person::getMonth() const {
    return month;
}

int Person::getDay() const {
    return day;
}

int Person::getYear() const {
    return year;
}

std::string Person::getBirthday() const {
    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
}





