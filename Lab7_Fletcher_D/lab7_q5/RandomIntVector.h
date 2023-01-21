#ifndef RANDOMINTVECTOR_H
#define RANDOMINTVECTOR_H

#include <vector>

class RandomIntVector : std::vector<int> {

private:
    std::vector<int> rand_ints {};
    int size = 0;
    int sum = 0;

public:
    RandomIntVector(int count_param);
    int get_total();
    double get_avg();
    void get_str();
};

#endif