/* 
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "Math.h"

using namespace std;

void prompt();

int main()
{
    string str;
    int exponent, base;
    Math math; // create object

    cout << "The MatheMagics App" << endl << endl;

    do {
        prompt(); // input options 
        cout << "Command: ";
        cin >> str;

        if(str == "square") {
            cout << "Enter a number to square: ";
            cin >> base;
            math.square(base); // squares via point in class
            cout << "Result: " << math.getResult() << endl << endl;
        }
        else if(str == "cube") {
            cout << "Enter a number to cube: ";
            cin >> base;
            math.cube(base); // cubes base via point in class
            cout << "Result: " << math.getResult() << endl << endl;
        }
        else if(str == "pow") {
            cout << "Enter the base: ";
            cin >> base;
            cout << "Enter the integer exponent: ";
            cin >> exponent;
            math.pow(base, exponent); // perform base to expontent via point in class
            cout << "Result: " << math.getResult() << endl << endl;
        }
    } while (str != "quit");

    cout << "Bye!" << endl;

    return EXIT_SUCCESS;
}
void prompt() 
{
    cout << "Comand Menu" << endl;
    cout << "------------" << endl;
    cout << left << setw(8) << "square:" << "perform squaring of a number" << endl;
    cout << setw(8) << "cube:" << "perform cubing of a number" << endl;
    cout << setw(8) << "pow:" << "raise a number to an integer power" << endl;
    cout << setw(8) << "quit:" << "quit the program" << endl << endl;
}