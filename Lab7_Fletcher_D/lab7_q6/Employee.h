#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>

class Employee : public Person {

private:
    std::string social_security;

public:
    std::string get_social_security() const;
    void set_social_security(std::string ssn_param);

};

#endif