#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string> 

class Customer : public Person {
    
private:
    std::string customer_number;

public:
    std::string get_customer_number() const;
    void set_customer_number(std::string cust_param);

};

#endif