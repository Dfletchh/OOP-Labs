/* 
* Author: Dean Fletcher
* Purpose: This program reads in a file of FIFA World Cup Winners. With the use of maps
*          of vectors it organizes the data so that all the years won will be in the same
*          map as the respective country. It then determines the champion with most wins
*          and outputs that conutry to the console.          
*/
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
// FIFA World Cup Winners //
    cout << "\nFIFA World Cup Winners\n\n" << endl;

    ifstream input_file("world_cup_champions.txt"); // open file
    if (input_file)                                 // if opened successfully
    {
        string line, year, country, champ;
        int wins = 0;
        map<string, vector<string> > fifa;
        stringstream ss;                  // buffer for string "line"

        getline(input_file, line); // remove first line of file
        while (getline(input_file, line)) // retrieves each line in file
        {
            ss.str(line);                 // replace string stream buffer w/ new_line
            ss.clear();                   // reset string stream error bit
            if (ss >> year >> country)    // parse buffer
            {
                fifa[country].push_back(year); // push year into vector via map key
            }
        }
        input_file.close();
        
        cout << left << setw(15) << "Country" << setw(6) << "Wins" << "Years" << endl; 
        cout << left << setw(15) << "=======" << setw(6) << "====" << "=====" << endl;

        for (auto winner : fifa) { // loop map
            cout << left << setw(15) << winner.first << setw(6) << winner.second.size(); // output key (country) and vector size (wins)
            if (wins < winner.second.size()) { // test for most chamionships won
                wins = winner.second.size();
                champ = winner.first;
            }
                for (auto yrs : winner.second) { // loop vector in map
                    if (yrs == winner.second.back()) { // check if last element in vector
                        cout << yrs << endl;
                    } else
                        cout << yrs << ", ";
                }
        }
        cout << endl << champ << " has won the most championships!\n" << endl;
    } else
        cout << "File error!" << endl;

    return EXIT_SUCCESS;
}