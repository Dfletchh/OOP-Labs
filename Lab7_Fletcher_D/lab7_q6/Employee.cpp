#include "Employee.h" 
#include <string>

std::string Employee::get_social_security() const {
    return social_security;
}
void Employee::set_social_security(std::string ssn_param) {
    social_security = ssn_param;
}