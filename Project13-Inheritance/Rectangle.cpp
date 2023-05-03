//
// Created by Brian Cassriel on 5/2/23.
//

#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle(double height, double width) : Shape(height, width) {
    type = "Rectangle";
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle destructor called" << std::endl;
}

void Rectangle::scale(double scaleFactor) {
    height *= scaleFactor;
    width *= scaleFactor;
}

double Rectangle::area() {
    return height * width;
}

double Rectangle::perimeter() {
    return height*2 + width*2;
}