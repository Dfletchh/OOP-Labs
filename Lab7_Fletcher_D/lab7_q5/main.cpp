/*
* Auhtor: Dean Fletcher
* Purpose: This program creates a RandomInt Vector class taht inherits the
*          vector class. This class allows a programmer to create a vector
*          of random integers from 1 to 100. The class has memeber functions
*          get_total, get_avg, and get_str, which work with the vector created. 
*          The output of this program will be a summary of the data held in the 
*          vector.
*/

#include "RandomIntVector.h"
#include "console.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int count;
    char ans;

    cout << "Random Integer List" <<  endl << endl;

    do {
    count = console::get_int("How many random integers should the list contain?: ", 0);
    RandomIntVector rand_ints(count); // Object of random integers 1 - 100 of size "count"

    cout << "\nRandom Integers" << endl;
    cout << "===============" << endl;

    cout << left << setw(11) << "Integers: ";  // Ouput vector of random integers
    rand_ints.get_str();

    cout << left << setw(11) << "Count: ";     // Output count
    cout << count << endl;

    cout << left << setw(11) << "Total: ";     // Gets sum of elements in the vector
    cout << rand_ints.get_total() << endl;

    cout << left << setw(11) << "Average: ";   // Returns the average of the elements
    cout << rand_ints.get_avg() << endl << endl;

    ans = console::get_char("Continue? (y/n): "); // continue

    while (ans != 'y' && ans != 'n') {         // Validation loop
        cout << "Invalid entry!" << endl;
        ans = console::get_char("Continue? (y/n): ");
    }

    } while (ans == 'y');

    cout << "Bye!" << endl << endl;
    return EXIT_SUCCESS;
}