#include "Math.h"

Math& Math::square(double base)
{
    this->result = base * base;
    return *this;
}
Math& Math::cube(double base)
{
    this->result = base * base * base;
    return *this;
}
Math& Math::pow(double base, int exp)
{
    if (exp == 0) {
        this->result = 1;
    }
    if (exp > 0) 
    {
        this->result = base;
        if (exp > 1) {
            for (int i = 1; i < exp; i++)
                this->result *= base;
        }
    }
    return *this;
}
int Math::getResult()
{
    return this->result;
}