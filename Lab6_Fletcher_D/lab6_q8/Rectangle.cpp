#include "Rectangle.h"
#include <string>
#include <iostream>


int Rectangle::Perimeter() {
    return 2 * (width + height);
}
int Rectangle::Area() {
    return width * height;
}
// Returns a string representation of the given object // 
std::string Rectangle::string_representation () {
    std::string rec_string;
    for (int i = 0; i < width; i++) { // first line
        rec_string += "* ";
    }
    for (int j = 0; j < height-2; j++) { // edges
        rec_string += "\n* ";
        for (int k = 0; k < width-2; k++) { // inner lines
            rec_string += "  ";
        }
        rec_string += "*";
    }
    rec_string += '\n';
    for (int m = 0; m < width; m++) { // last line
        rec_string += "* ";
    }
    return rec_string;
}
// Getters and Setteres // 
void Rectangle::set_height(int height_param) {
    height = height_param;
}
void Rectangle::set_width(int width_param) {
    width = width_param;
}
int Rectangle::get_height() const {
    return height;
}
int Rectangle::get_width() const {
    return width;
}