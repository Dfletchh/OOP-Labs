#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

class Task
{
    private:
    std::string task;
    int status;

    public:
    friend std::ostream& operator << (std::ostream& output, Task& task);
    std::string get_task();
    void set_task(std::string task_param);
    int get_status();
    void set_status(int status_param);

};

#endif