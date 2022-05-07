#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{    
    Dictionary dictionary;

    // add an entry
    dictionary.insertSorted("Bob", 5, 10, 2005);
    dictionary.insertSorted("Tim", 1, 10, 2010);
    dictionary.insertSorted("Jack", 8, 30, 2020);
    dictionary.insertSorted("Tom", 3, 1, 2020);
    dictionary.insertSorted("Jeff", 5, 20, 2006);
    dictionary.insertSorted("Justin", 5, 2, 2006);

    // display the name and birthday of every entry in the dictionary
    cout << "Displaying current dictionary" << endl;
    dictionary.displayAll();
    cout << endl;

    // remove an entry
    dictionary.remove("Jack");
    dictionary.remove("Tim");
    
    cout << "Displaying dictionary after removing Jack and Tim" << endl;
    dictionary.displayAll();
    cout << endl;

    // search the dictionary for the birthday for a given name
    cout << "Showing Bob's birthday" << endl;
    cout << "Bob's Birthday: " << dictionary.getBirthdayByName("Bob") << endl;   
    cout << endl;

    // display everyone in the dictionary who was born in a given month
    cout << "Displaying everyone with their birthday in the month of May (5)" << endl;
    dictionary.displayAllInMonth(5);

    dictionary.deallocateMemory();

    return 0;
}

/* Output

Displaying current dictionary
Name: Bob, Birthday: 2005-5-10
Name: Jack, Birthday: 2020-8-30
Name: Jeff, Birthday: 2006-5-20
Name: Justin, Birthday: 2006-5-2
Name: Tim, Birthday: 2010-1-10
Name: Tom, Birthday: 2020-3-1

Displaying dictionary after removing Jack and Tim
Name: Bob, Birthday: 2005-5-10
Name: Jeff, Birthday: 2006-5-20
Name: Justin, Birthday: 2006-5-2
Name: Tom, Birthday: 2020-3-1

Showing Bob's birthday
Bob's Birthday: 2005-5-10

Displaying everyone with their birthday in the month of May (5)
Name: Bob, Birthday: 2005-5-10
Name: Jeff, Birthday: 2006-5-20
Name: Justin, Birthday: 2006-5-2

*/