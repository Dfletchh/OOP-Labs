/*
* Auhtor: Dean Fletcher
* Purpose: This program creates objects based on a customer or empolyee selection. The instance
*          created is then outputed to the user via the console. Both a employee and customer
*          instance share first name, last name, and email paramaters. Where as a SSN and 
*          customer ID differ for each object type.
*/

#include <iostream>
#include <limits>

#include "Employee.h"
#include "Customer.h"

using namespace std;

void newCustomer();
void newEmployee();
template<class type> void objStandard(type &obj);
char get_char(string prompt, char param1, char param2, bool add_blank_line = true);

int main() 
{
    char ans = ' ';

    cout << "\nCustomer/Employee Data Entry" << endl << endl;

    do 
    {   
        ans = get_char("Customer or employee? (c/e): ", 'c', 'e'); // Input validation for object type

        cout << "DATA ENTRY" << endl;
        if (ans == 'c') {
            newCustomer(); // Function for customer object
        } else 
            newEmployee(); // Function for employee object

        ans = get_char("Continue? (y/n): ", 'y', 'n'); // Input validation to continue

    } while (ans == 'y');

    cout << "Bye!" << endl << endl;

    return EXIT_SUCCESS;
}

// Function creates a customer object //
void newCustomer() 
{
    string input_data = "";
    Customer customer;

    objStandard(customer); // function for setting standard info of object
    cout << "Number: ";
    cin >> input_data;
    customer.set_customer_number(input_data); // set customer number

    cout << "\nCUSTOMER" << endl;
    cout << "Name: " << customer.full_name() << endl;
    cout << "Email: " << customer.get_email() << endl;
    cout << "Number: " << customer.get_customer_number() << endl << endl;
}

// Function creates a employee object //
void newEmployee() 
{
    string input_data = "";
    Employee employee;

    objStandard(employee); // function for setting standard info of object
    cout << "SSN: ";
    cin >> input_data;
    employee.set_social_security(input_data); // set SSN number

    cout << "\nEMPLOYEE" << endl;
    cout << "Name: " << employee.full_name() << endl;
    cout << "Email: " << employee.get_email() << endl;
    cout << "SSN: " << employee.get_social_security() << endl << endl;
}

// Function for setting standard information of the object passed //
template<class type> void objStandard(type &obj)
{ 
    string input = "";
    cout << "First name: ";
    cin >> input;
    obj.set_first_name(input); // set first name

    cout << "Last name: ";
    cin >> input;
    obj.set_last_name(input); // set last name

    cout << "Email: ";
    cin >> input;
    obj.set_email(input); // set email
}

// Input validation function //
char get_char(string prompt, char param1, char param2, bool add_blank_line) 
{
    char choice = 'n';
    cout << prompt;
    cin >> choice;
    while (choice != param1 && choice != param2) {  // Validation loop
        cout << "Invalid entry!" << endl << prompt;
        cin >> choice;
    }
    if (add_blank_line)
        cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
    return choice;
}