/* 
* Auhtor: Dean Fletcher
* Purpose: This program takes a height and width from the user to create an object of type 
*          Rectangle. The programs intention is to give the perimeter and area of from 
*          the input and output a string represetation of the rectangle with '*' chars.
*/

#include "Rectangle.h"
#include "console.h"
#include <iostream>
#include <iomanip> 

using namespace std;

int main() 
{
    Rectangle rec;
    int height, width;
    char ans;

    cout << "Rectangle Calculator" << endl << endl;

    do {
        height = console::get_int("Height: ", 0); // input validation
        rec.set_height(height);

        width = console::get_int("Width: ", 0); // input validation 
        rec.set_width(width);

        cout << "Perimeter: ";
        cout << rec.Perimeter() << endl; // returns perimeter of the object

        cout << left << setw(11) << "Area: "; // formatting 
        cout << rec.Area() << endl; // returns area of the object

        cout << rec.string_representation() << endl << endl; // outputs '*' representation of object

		ans = console::get_char("Continue? (y/n): "); // input validation 
        
        while (ans != 'n' && ans != 'y') // input validation 
		{
			cout << "Invalid entry!" << endl;
			ans = console::get_char("Continue? (y/n): ");
		}
    } while (ans == 'y');

    cout  << "Bye!" << endl;
    return 0;
}