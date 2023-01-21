#include "TaskIO.h"
#include "Task.h"
#include <fstream>
#include <vector>

TaskList TaskIO::read(std::string file_param)
{
    std::string line,str;
    int status;
    TaskList all_tasks; // create object

    std::ifstream ifile(file_param); // open file for reading
    if(ifile.is_open()) {            // if opened 
        while(getline(ifile, line, '\t')) // line by line
        {
            ifile >> status; // pull int status
            getline(ifile, str, '\n'); // removes '\n' from buffer
            
            Task task; // create new task object
            task.set_task(line);
            task.set_status(status);

            all_tasks += task; // add taks to running TaskList
        }
    } else 
        std::cout << "File Error!" << std::endl;
        
    ifile.close();
    return all_tasks;
}
void TaskIO::write(std::string file_param, TaskList task_param)
{
    std::ofstream ofile(file_param);
    for(int i=0; i < task_param.get_tasks().size(); i++)
        ofile << task_param[i];
    ofile.close();
}