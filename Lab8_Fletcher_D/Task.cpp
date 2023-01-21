#include "Task.h"

std::ostream& operator << (std::ostream &output, Task &task)
{
    output << task.get_task() << '\t' << task.get_status() << '\n';
    return output;
}
std::string Task::get_task()
{
    return task;
}
void Task::set_task(std::string task_param)
{
    task = task_param;
}
int Task::get_status()
{
    return status;
}
void Task::set_status(int status_param)
{
    status = status_param;
}