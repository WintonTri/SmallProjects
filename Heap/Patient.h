/** @file Patient.h  */
#ifndef _PATIENT
#define _PATIENT

#include <string>

class Patient
{
private:
    int             priority;
    std::string        name;  
public:
    Patient();
    Patient(int aPriority, std::string aName);
    int getPriority() const;
    std::string getName() const;

    friend bool operator<(const Patient &left, const Patient &right);
    friend bool operator>(const Patient &left, const Patient &right);

}; // end Patient

//#include "Patient.cpp"
#endif