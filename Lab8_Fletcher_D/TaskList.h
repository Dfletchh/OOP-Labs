#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include "Task.h"

class TaskList
{
    private:
    std::vector<Task> tasks;

    public:
    friend TaskList& operator += (TaskList& list_param, Task task_to_add);
    Task& operator[](int index_param);
    std::vector<Task> get_tasks();

};

#endif