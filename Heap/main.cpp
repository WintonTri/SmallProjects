
#include <iostream>
#include "Patient.h"
#include "Heap.h"

using namespace std;


int main()
{ 
    Heap ER;

    ER.add(5, "Bob");
    ER.add(9, "Mary");
    ER.add(1, "Max");
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    ER.add(3, "Julio");
    ER.add(7, "Stacy");
    ER.add(4, "Paul");
    ER.add(2, "Reiko");
    ER.add(6, "Jennifer");
    ER.add(5, "Chang");
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop().getName() << " will now see the doctor.\n";
    ER.remove();

    // I assume that I do not need to deallocate the array since ER.remove() is used?

    return 0;
}

/** Output
Mary will now see the doctor.
Stacy will now see the doctor.
Jennifer will now see the doctor.
Chang will now see the doctor.
Bob will now see the doctor.
Paul will now see the doctor.
Julio will now see the doctor.
Reiko will now see the doctor.
Max will now see the doctor.
*/