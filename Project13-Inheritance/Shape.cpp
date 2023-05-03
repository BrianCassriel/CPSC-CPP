//
// Created by Brian Cassriel on 5/2/23.
//

#include "Shape.h"

#include <iostream>

Shape::Shape(double height, double width) {
    this->height = height;
    this->width = width;
}

Shape::~Shape() {
    std::cout << "Shape destructor called" << std::endl;
}

void Shape::displayProperties() {
    std::cout << "Shape Type: " << type << " Height: " << height << " Width: " << width << std::endl;
}