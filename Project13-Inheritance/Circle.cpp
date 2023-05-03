//
// Created by Brian Cassriel on 5/2/23.
//

#include "Circle.h"

#include <iostream>

Circle::Circle(double height, double width) : Shape(height, width) {
    this->height = height;
    this->width = width;
    type = "Circle";
}

Circle::~Circle() {
    std::cout << "Circle destructor called" << std::endl;
}

void Circle::scale(double scaleFactor) {
    height *= scaleFactor;
    width *= scaleFactor;
}

double Circle::area() {
    return 0.25 * M_PI * pow(width, 2);
}

double Circle::perimeter() {
    return M_PI * width;
}