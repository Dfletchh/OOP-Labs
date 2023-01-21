#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {

private: 
    std::string first_name;
    std::string last_name;
    std::string email;

public:
    std::string full_name();
    std::string get_first_name()const;
    std::string get_last_name() const;
    std::string get_email() const;
    void set_first_name(std::string first_param);
    void set_last_name (std::string last_param);
    void set_email(std::string email_param);

};

#endif