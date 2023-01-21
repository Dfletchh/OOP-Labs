/* 
* Auhtor: Dean Fletcher
* Purpose: This program reads the sales for 12 months from a file and calculates the total yearly 
*          sales as well as the average monthly sales. The user can enter ‘m’, ‘y’, or ‘x’ as 
*          commands to view the sales, yearly summary, or exit the program, respectively.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Function Prototypes
void sales_report(char request);
char get_char(std::string prompt, bool add_blank_line = true);
void discard_remaining_chars();

int main()
{
    char option;
    cout << "Monthly Sales\n\n"
         << "COMMAND MENU\n"
         << "m - View monthly sales\n"
         << "y - View yearly summary\n"
         << "x - Exit program"
         << endl;
    while (option != 'x') // Loop until user exits program
    {
        option = get_char("\nCommand: "); // function call to test for valid char input
        option = tolower(option);         // input correction
        switch (option)
        {
        case 'm':
            cout << "MONTHLY SALES" << endl;
            sales_report(option); // prompts monthly sales from a file
            break;
        case 'y':
            cout << "YEARLY SUMMARY" << endl;
            sales_report(option); // prompts yearly sales from a file
            break;
        case 'x':
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Invalid command. Try again.\n";
        }
    }
    return 0;
}
// Function opens the file and performs the desired user task
void sales_report(char request)
{
    ifstream input_file("monthly_sales.txt"); // opens file
    if (input_file)                           // if opened successfully
    {
        string line, month;
        double sales, sum;
        int year = 12;
        stringstream ss; // buffer for string "line"

        cout << fixed << setprecision(2);
        while (getline(input_file, line)) // retrieves each line in file
        {
            ss.str(line);             // replace string stream buffer w/ line
            ss.clear();               // reset string stream error bit
            if (ss >> month >> sales) // parsing buffer
            {
                if (request == 'm') // format and outut monthly report
                {
                    cout << left << setw(10) << month
                         << right << setw(10) << round((sales * 100)) / 100 << endl;
                }
                else
                    sum += sales; // add for annual sales report
            }
        }
        input_file.close();
        if (request == 'y') // format and output yearly sales
        {
            sum = round((sum * 100)) / 100; // round to 2 decimal places
            double average = round((sum / year) * 100) / 100;
            cout << left << setw(16) << "Yearly total:"
                 << right << setw(16) << sum
                 << left << setw(16) << "\nMonthly average:"
                 << right << setw(16) << average << endl;
        }
    }
}
// function gets a vailid data type from user
char get_char(std::string prompt, bool add_blank_line)
{
    char choice = 'x';
    std::cout << prompt;
    std::cin >> choice;
    if (add_blank_line)
        std::cout << std::endl;

    discard_remaining_chars();
    return choice;
}
// define helper function for get_char()
void discard_remaining_chars()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}