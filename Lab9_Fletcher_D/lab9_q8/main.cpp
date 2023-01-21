/* 
 * Author: Dean Fletcher
 * 
 * Purpose: The purpose of this program is to create a 
 *      running list of pet names and species utilizing 
 *      dynamically allocated memory. 
*/
#include <iostream>
#include <vector>
#include "Pet.h"

using namespace std;

bool getChar();

int main()
{
    string name, species;
    vector<Pet*> pets; // vector of pointers to objects
    
    cout << "Dynamic Pets" << endl << endl;
    do 
    {
        cout << "Enter the pet's name: ";
        cin >> name;
        cout << "Enter the pet's species: ";
        cin >> species;

        Pet* pet = new Pet(name, species); // create object w/ dynamic memory
        pets.push_back(pet); // add object to the list of pets

    } while (getChar()); // continue on 'y'

    for (int i=0; i < pets.size(); i++) // loop through pets in the list 
    {
        cout << pets[i]->get_name() << " is a(n) " << pets[i]->get_species() << endl;
        delete pets[i]; // deallocate memory
    }

    cout << endl << "Bye!" << endl;
    return EXIT_SUCCESS;
}
// Input validation function //
bool getChar() 
{
    char ans;
    bool another; 
    cout << "Add another pet? (y/n): ";
    cin >> ans;
    cout << endl;
    while (ans != 'y' && ans != 'n') { // validation loop
            cout << "Invalid entry..." << endl;
            cout << "Add another pet? (y/n): ";
            cin >> ans;
            cout << endl;
    }
    return (ans == 'y') ? true : false;
}