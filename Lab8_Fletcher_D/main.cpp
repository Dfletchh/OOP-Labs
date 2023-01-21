/*
*
*
*/

#include <iostream>
#include <fstream>
#include <limits>

#include "TaskList.h"
#include "TaskIO.h"

using namespace std;

char get_char(string prompt, bool add_blank_line=false);
void view_tasks(TaskList& task_param);
void view_completed(TaskList& task_param);
void add_task(TaskList& task_param);
void complete_task(TaskList& task_param);

int main ()
{
    char input = ' ';
    cout << "Task List" << endl << endl;

    cout << "COMMANDS" << endl;
    cout << "v - View pending tasks\n"
         << "a - Add a task\n"
         << "c - Complete a task\n"
         << "h - History of completed tasks\n"
         << "x - Exit" << endl;

    TaskList task_list = TaskIO::read("task_list.txt"); // call to read file store in tasks
    while (input != 'x')
    {
        cout << endl;
        input = get_char("Command: "); // Input validation
        switch (input) {
            case 'v':
                view_tasks(task_list);
                break;
            case 'a':
                add_task(task_list);
                break;
            case 'c':
                complete_task(task_list);
                break;
            case 'h':
                view_completed(task_list);
                break;
        }
    }
    cout << "Bye!" << endl;
    return EXIT_SUCCESS;
}
// Input validation function //
char get_char(string prompt, bool add_blank_line) 
{
    char choice = ' ';
    cout << prompt;
    cin >> choice;
    while (choice != 'v' && choice != 'a' && choice != 'c' // Validation loop
           && choice != 'h' && choice != 'x') 
    {  
        cout << "Invalid entry!" << endl << prompt;
        cin >> choice;
    }
    if (add_blank_line)
        cout << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
    return choice;
}
// Function for reading unompleted tasks //
void view_tasks(TaskList& task_param)
{
    int count = 0;
    for(int i=0; i < task_param.get_tasks().size(); i++)
    {
        if(task_param[i].get_status() == 0) // if task flag is 0
        {   
            cout << ++count << ". " << task_param[i].get_task() << endl; // output task
        } 
    }
}
// Function for adding a task to the task list //
void add_task(TaskList& task_param)
{
    string str;
    Task task;

    cout << "Description: ";
    //cin.ignore();
    getline(cin, str);
    task.set_task(str); // set description
    task.set_status(0); // set status 
    task_param += task; // add to task list
    TaskIO::write("task_list.txt", task_param); // call to update the file
}
// Function for completing a task in the task list //
void complete_task(TaskList& task_param)
{
    int num = 0, index = 0, count = 0;
    for(int i = 0; i < task_param.get_tasks().size(); i++) // task count
    {
        if(task_param[i].get_status() == 0) // if task flag is 0
            count++;
    }
    cout << "Number: ";
    cin >> num;
    while (num > count) // test task range 
    {
        cout << "\nInvalid, Try again\nNumber: ";
        cin >> num;
    }
    count = 0; // reset counter 
    for(int j = 0; j < task_param.get_tasks().size(); j++)
    {
        index++;
        if(task_param[j].get_status() == 0) // if task flag is 0
        {
            count++;
            if (count == num)
                task_param[index-1].set_status(1); // change task status
        }
    }
    TaskIO::write("task_list.txt", task_param); // call to update the file
}
// Function for reading completed tasks //
void view_completed(TaskList& task_param)
{
    int count = 0;
    for(int i = 0; i < task_param.get_tasks().size(); i++)
    {
        if(task_param[i].get_status() == 1) // if task flag is 0
        {  
            cout << ++count << ". " << task_param[i].get_task() << " (DONE!)\n"; 
        }
    }
}