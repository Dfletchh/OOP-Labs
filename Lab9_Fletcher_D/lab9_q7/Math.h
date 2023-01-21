#ifndef MATH_H
#define MATH_H

class Math
{
    private:
        double result;
    public:
        Math& square(double base);
        Math& cube(double base);
        Math& pow(double base, int exp);
        int getResult();
};

#endif