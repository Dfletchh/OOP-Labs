#ifndef TASKIO_H
#define TASKIO_H

#include "TaskList.h"

class TaskIO
{
    public:
    static TaskList read(std::string file_param);
    static void write(std::string file_param, TaskList task_param);

};

#endif