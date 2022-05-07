/** @file Patient.cpp */

#include "Patient.h"
#include <string>

Patient::Patient() {
}

Patient::Patient(int aPriority, std::string aName) {
    priority = aPriority;
    name = aName;
}

int Patient::getPriority() const {
    return priority;
}

std::string Patient::getName() const {
    return name;
}

bool operator<(const Patient &left, const Patient &right) {
    return left.getPriority() < right.getPriority();
}

bool operator>(const Patient &left, const Patient &right) {
    return left.getPriority() > right.getPriority();
}




