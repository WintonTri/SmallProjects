#include <exception>
#include <iostream>
#include <list>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

bool isPalindrome(string str);

int main() {
    const int CHECKS = 7;
    string strings[CHECKS] = {"Banana", "Apple", "HelloH", "White", "aabbcc", "appa", "tpaffapt"};
    for (int i = 0 ; i < CHECKS; i++) {
        string s = strings[i];
        bool palindrome = isPalindrome(s);
        
        cout << s << " is";

        if (!palindrome) {
            cout << " NOT";
        }         

        cout << " Palindrome." << endl << endl;
    }

}

bool isPalindrome(string str) {

    // Creating a new empty stack and queue
    Stack* aStack = new Stack();
    Queue* aQueue = new Queue();

    // Loading the queue and stack
    char ch;
    int l = str.length();
    for (int i = 0; i < l; i++) {
        ch = str.at(i);
        // cout << "Adding " << ch << " to the queue and stack" << endl;
        aStack->push(ch);
        aQueue->enqueue(ch);
    }

    // Checking if the input is palindrome
    while (!aQueue->isEmpty() && !aStack->isEmpty())
    {
        char frontChar = aQueue->peekFront();
        char backChar = aStack->peek();
        aQueue->dequeue();
        aStack->pop();

        cout << "Comparing Front Char: " << frontChar << " with Back Char: " << backChar << endl;
        if (frontChar != backChar) {
            cout << "Front and back chars are not the same, String is not Palindrome!" << endl;
            return false;
        }
            
    }

    return true;
}

/** Output
[wgee11@hills ~]$ ./a.out
Comparing Front Char: B with Back Char: a
Front and back chars are not the same, String is not Palindrome!
Banana is NOT Palindrome.

Comparing Front Char: A with Back Char: e
Front and back chars are not the same, String is not Palindrome!
Apple is NOT Palindrome.

Comparing Front Char: H with Back Char: H
Comparing Front Char: e with Back Char: o
Front and back chars are not the same, String is not Palindrome!
HelloH is NOT Palindrome.

Comparing Front Char: W with Back Char: e
Front and back chars are not the same, String is not Palindrome!
White is NOT Palindrome.

Comparing Front Char: a with Back Char: c
Front and back chars are not the same, String is not Palindrome!
aabbcc is NOT Palindrome.

Comparing Front Char: a with Back Char: a
Comparing Front Char: p with Back Char: p
Comparing Front Char: p with Back Char: p
appa is Palindrome.

Comparing Front Char: t with Back Char: t
Comparing Front Char: p with Back Char: p
Comparing Front Char: a with Back Char: a
Comparing Front Char: f with Back Char: f
Comparing Front Char: f with Back Char: f
Comparing Front Char: a with Back Char: a
Comparing Front Char: p with Back Char: p
tpaffapt is Palindrome.

[wgee11@hills ~]$

*/