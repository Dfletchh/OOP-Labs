#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle {
private:
    int height;
    int width;

public:
    int Perimeter();
    int Area();
    std::string string_representation ();

    void set_height(int height_param);
    void set_width(int width_param);
    int get_height() const;
    int get_width() const;
};
#endif