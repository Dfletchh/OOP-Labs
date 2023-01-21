/*
* Author: Dean Fletcher
* Program: This program tests if a number between 1 - 5000 is prime. The value
*          tested is provided by the user and is check for validity. Any values
*          that are factors of the number is stored in a vector. Any number that
*          has factors other then 1 and itself are considered prime by definition.
*/
#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

bool prime_test(vector<int> &test, int num);
int get_int(string prompt, int min, int max);
char get_char(string prompt);
void discard_remaining_chars();
void handle_invalid_input();
bool check_range(double num, double min, double max);

int main()
{
    vector<int> prime_values;
    int num;
    char again = ' ';
    int min = 1;
    int max = 5000;
    bool is_prime = false;

    cout << endl << "Prime Number Checker" << endl << endl;

    do {

        num = get_int("Please enter an integer 1 to 5000: ", min, max); // input validation
        is_prime = prime_test(prime_values, num); // bool for if prime

        if (!is_prime) // if not prime procedure 
        {
            cout << num << " is NOT a prime number." << endl;
            cout << "It has " << prime_values.size() << " factors: "; // total divisible numbers

            for (int it : prime_values) { // output vector of divisible numbers
                cout << it << ' ';
            }
            cout << endl << endl;
        } else 
            cout << num << " is a prime number." << endl << endl; // else prime 
        
        prime_values.clear(); // empty values held in container
        again = get_char("Try agian? (y/n): "); // input validation for do/while loop
        
    } while (again != 'n');

    cout << "Bye! " << endl << endl;

    return 0;
}
// Function tests if prime and pushes values into a vector. Returns //
// true if onlydivisible by 1 and itself, otherwise return false.   //
bool prime_test(vector<int> &test, int num)
{
    for (int i=1; i<=num; i++) 
    {
        if (num%i == 0) 
            test.push_back(i);
    }
    if (test.size() <= 2) // if only 1 and itself, then prime
        return true;
    return false;
}
// Input validation for int type //
int get_int(string prompt, int min, int max)
{
    int num = 0;
    bool is_valid = false;
    while (!is_valid)
    {
        cout << prompt;
        if (!(cin >> num)){
            handle_invalid_input(); // Prompt error and clear stream
        } else {
            discard_remaining_chars(); // clears stream
            is_valid = check_range(num, min, max);
        }
    }
    return num;
}
// Input validation for char type //
char get_char(string prompt)
{
    char choice = ' ';
    while (true) 
    {
        cout << prompt;
        cin >> choice;
        cout << endl;
        choice = tolower(choice); // cast to lowercase
        if (choice == 'n' || choice == 'y') {
            discard_remaining_chars(); // clear stream
            break;
        } else
            handle_invalid_input(); // Prompt error and clear stream
    }
    return choice;
}
// Helper functions for input validation //
bool check_range(double num, double min, double max)
{
    if (num < min) {
        cout << "Error! Number must be greater than "
                    << min << ". Try again.\n" << endl;
        return false;
    }
    else if (num > max) {
        cout << "Error! Number must be less than "
                    << max << ". Try again.\n" << endl;
        return false;
    } else 
        return true;
}
void discard_remaining_chars()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void handle_invalid_input()
{
    cout << "Error! Invalid. Try again.\n" << endl;
    cin.clear(); // clear the failure flag
    discard_remaining_chars();
}