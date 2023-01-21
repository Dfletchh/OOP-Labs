#include "RandomIntVector.h"
#include <cstdlib>
#include <iostream>

// Constructor creates vector of random numbers
RandomIntVector::RandomIntVector (int count_param) {
    vector vec;
    size = count_param;
    srand(time(NULL));
    for (int i =0; i < count_param; i++){
        int num = (rand() % 100) + 1; // 1 to 100   
        vec.push_back(num);
    }
    rand_ints = vec;
}
int RandomIntVector::get_total() {
    sum = 0;
    for (int it : rand_ints) {
        sum += it;
    }
    return sum;
}
double RandomIntVector::get_avg() {
    return static_cast<double>(sum)/size;
}
void RandomIntVector::get_str() {
    for (int i = 0; i < rand_ints.size()-1; i++){
         std::cout << rand_ints[i] << ", ";
    }
    std::cout << rand_ints.back() << std::endl; // last element
}