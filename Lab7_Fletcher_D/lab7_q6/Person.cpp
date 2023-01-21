#include "Person.h"
#include <string>


std::string Person::full_name() {
    return first_name + " " + last_name;
}
std::string Person::get_first_name() const {
    return first_name;
}
std::string Person::get_last_name() const {
    return last_name;
}
std::string Person::get_email() const {
    return email;
}
void Person::set_first_name(std::string first_param) {
    first_name = first_param;
}
void Person::set_last_name(std::string last_param) {
    last_name = last_param;
}
void Person::set_email(std::string email_param) {
    email = email_param;
}