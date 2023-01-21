/* 
* Auhtor: Dean Fletcher
* Purpose: This program receives five doubles from the user. It prints the sum, average,
*          product, and the absolute value (using the cmath library) of each number to 
*          the console.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double num1, num2, num3, num4, num5;

    cout << "Enter five numbers: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    // make calculations
    double sum = num1 + num2 + num3 + num4 + num5;
    double average = sum / 5;
    double product = num1 * num2 * num3 * num4 * num5;
    double absolute_num1 = sqrt(pow(num1, 2));
    double absolute_num2 = sqrt(pow(num2, 2));
    double absolute_num3 = sqrt(pow(num3, 2));
    double absolute_num4 = sqrt(pow(num4, 2));
    double absolute_num5 = sqrt(pow(num5, 2));

    // output results
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Product: " << product << endl;
    cout << "Absolute Values: " << absolute_num1 << " ";
    cout << absolute_num2 << " ";
    cout << absolute_num3 << " ";
    cout << absolute_num4 << " ";
    cout << absolute_num5 << endl;
    cout << "Done" << endl
         << endl;

    return 0;
}