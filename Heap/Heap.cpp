/** @file Heap.cpp */

#include "Patient.h"
#include "Heap.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

Heap::Heap() {
    items = new Patient[MAX_ITEMS];
}


bool Heap::add(int aPriority, std::string aName) {
    if (itemCount == MAX_ITEMS) {
        return false;
    }

    // Set it as the very last element (for now)
    items[itemCount] = Patient(aPriority, aName);

    int newDataIndex = itemCount;
    bool inPlace = false;
    while ((newDataIndex > 0) && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if (items[newDataIndex].getPriority() < items[parentIndex].getPriority())
        {
            inPlace = true;
        } else {
            swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
        }
    }

    itemCount++;
    return true;
}

// items array and item count is not needed in the params
void Heap::heapRebuild(int rootIndex) { 
    bool isLeaf = 2 * rootIndex + 1 > itemCount;
    if (!isLeaf)
    {
        int largerChildIndex = 2 * rootIndex + 1; // Left child index

        // now see if there is a right child which is larger than left child
        int rightChildIndex = 2 * rootIndex + 2;
        bool hasRightChild = rightChildIndex < itemCount;
        if (hasRightChild)
        {
            if(items[rightChildIndex].getPriority() > items[largerChildIndex].getPriority())
            {
                largerChildIndex = rightChildIndex; // Larger child index
            }           
        }

        // If item in root is smaller than item in larger child, swap items
        bool childLarger = items[rootIndex].getPriority() < items[largerChildIndex].getPriority();
        if (childLarger)
        {
            // Swap items child and root
            swap(items[rootIndex], items[largerChildIndex]);

            // Recursion to continue the "trickle"
            heapRebuild(largerChildIndex);
        }
    }

}

// Removing steps
// -> Remove the current root
// -> Set last item to position 0 (remove last item)
// -> Use heapRebuild or the "trickle"
bool Heap::remove() {
    if (itemCount == 0) {
        return false;
    }

    int lastItemIndex = itemCount - 1;
    //cout << "Removing Item: " << items[0].getName() << ", Priority: " << items[0].getPriority() << endl;
    items[0] = items[lastItemIndex];
    //cout << "Temp Root Item: " << items[0].getName() << ", Priority: " << items[0].getPriority() << endl;
    // items[lastItemIndex] = nullptr; //TODO

    heapRebuild(0);

    itemCount--;
    return true;
}

Patient Heap::peekTop() {
    return items[0];
}