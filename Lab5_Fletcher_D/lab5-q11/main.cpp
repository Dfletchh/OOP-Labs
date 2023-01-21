/*
* Author: Dean Fletcher
* Program: This program fills a container with 10 random integers ranging for 1 - 100 inclusively.
*          It uses STL sort algorithm to sort the container in ascending order. It then uses input 
*          validation to retrieve a value for the user in the alotted range or 0 to exit. The value 
*          obtained is used to testy the STL binary search algorithm to see if the value is held in 
*          the container. 
*/

#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void random_numbers();
int get_int(string prompt, int min, int max);
void discard_remaining_chars();
void handle_invalid_number();
bool check_range(double num, double min, double max);
vector<int> RANDOM_NUMS;

int main()
{
    int input;
    cout << "\nBinary Search program" << endl;
    cout << "\nEnter 0 to exit\n" << endl;

    random_numbers(); // creates vector of random numbers
    cout << "Random Numbers:\t[";
    for (int i=0; i<RANDOM_NUMS.size()-1; i++)
        cout << RANDOM_NUMS.at(i) << ", ";
    cout << RANDOM_NUMS.at(9) << "]" << endl; // last element in vector

    while (true) { // Guessing loop
        int min =0;
        int max = 100;
        string prompt = "\nEnter a number from 1 to 100: ";

        input = get_int(prompt, min, max);

        if (input==0) { // exit command
            break;
        }
        bool found = binary_search(RANDOM_NUMS.begin(), RANDOM_NUMS.end(), input); // search algorithm

        if (found) {
            cout << input << " is in random numbers." <<  endl;
        } else
            cout << input << " is NOT in random numbers." << endl;
    }

    cout << "\nBye!\n" << endl;
    return 0;
}
// Function generates a random number and pushes to vector
void random_numbers() {
    srand(time(NULL));

    for (int i=0; i<10; i++) 
        RANDOM_NUMS.push_back((rand()%100) + 1);
    sort(RANDOM_NUMS.begin(), RANDOM_NUMS.end()); // sorts the vector in ascending order
}

// input validation function
int get_int(string prompt, int min, int max)
{
    int num = 0;
    bool is_valid = false;

    while (!is_valid)
    {
        cout << prompt;
        if (!(cin >> num)){
            handle_invalid_number();
        } else {
            discard_remaining_chars();
            is_valid = check_range(num, min, max);
        }
    }
    return num;
}
// helper functions
void discard_remaining_chars()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void handle_invalid_number()
{
    cout << "Error! Invalid number. Try again.\n";
    cin.clear(); // clear the failure flag
    discard_remaining_chars();
}
// Checks if input is in range
bool check_range(double num, double min, double max)
{
    if (num < min) {
        cout << "Error! Number must be greater than "
                    << min << ". Try again.\n";
        return false;
    }
    else if (num > max) {
        cout << "Error! Number must be less than "
                    << max << ". Try again.\n";
        return false;
    } else {
        return true;
    }
}