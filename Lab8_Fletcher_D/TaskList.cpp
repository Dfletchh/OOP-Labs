#include "TaskList.h"

std::vector<Task> TaskList::get_tasks()
{
    return tasks; // vector of tasks
}
TaskList& operator += (TaskList& list_param, Task task_to_add)
{
    list_param.tasks.push_back(task_to_add); // push task to vector 
    return list_param;
}
Task& TaskList::operator [] (int index)
{
    return tasks[index]; // task element at index
}