#include "Customer.h"
#include <string>

std::string Customer::get_customer_number() const {
    return customer_number;
}
void Customer::set_customer_number(std::string cust_param) {
    customer_number = cust_param;
}