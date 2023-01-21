/* 
* Auhtor: Dean Fletcher
* Purpose: This program reads in an arbritrary number of characters from the user. 
*          At the sentinel value ('0') the string is printed with ONLY the vowels 
*          capitilized and every other character lowercased. 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    char input_char;
    string output_string;

    // loop checks for vowels and capitilizes them via a switch
    do
    {
        cout << "Enter a character: ";
        cin >> input_char;
        input_char = tolower(input_char); // correction for uppercase input
        switch (input_char)
        {
        case 'a':
            output_string += toupper(input_char);
            break;
        case 'e':
            output_string += toupper(input_char);
            break;
        case 'i':
            output_string += toupper(input_char);
            break;
        case 'o':
            output_string += toupper(input_char);
            break;
        case 'u':
            output_string += toupper(input_char);
            break;
        default:
            if (input_char != '0')
                output_string += input_char; // creates output string
        }
    } while (input_char != '0'); // repeats until '0' is entered by user
    cout << output_string << endl;
    return 0;
}