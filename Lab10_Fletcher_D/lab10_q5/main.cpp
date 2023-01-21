/* 
 * Author: Dean Fletcher
 * 
 * Purpose: The purpose of this program is to Code a custom container 
 * for a multiset (also known as a bag) that stores data of any type 
 * in no particular order and allows duplicates. Then, write some code
 * that tests this custom container
 */

#include <iostream>
#include "ArrayBag.h"

using namespace std;

int main()
{
    ArrayBag<string> bag; // create custom container

    bag.add("John"); // add elements
    bag.add("Joel");
    bag.add("Samantha");
    bag.add("John");

    cout << "\nMultiset/Bag Test" << endl << endl;
    cout << "ELEMENTS" << endl;

    bag.printElements(); // prompt current elements
    cout << endl << boolalpha; // setup true/false
    cout << "isEmpty() returns " << bag.isEmpty() << endl;
    cout << "isFull() returns " << bag.isFull() << endl;
    cout << "contains() for John returns " << bag.contains("John") << endl;
    cout << "contains() for Bob returns " << bag.contains("Bob") << endl;
    cout << endl;

    cout << "Calling remove()" << endl << endl;
    bag.remove(); // remove element

    cout << "ELEMENTS" << endl;
    bag.printElements(); // remaining elements
    cout << endl;

    return EXIT_SUCCESS;
}