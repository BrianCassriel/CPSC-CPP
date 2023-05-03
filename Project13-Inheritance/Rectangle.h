//
// Created by Brian Cassriel on 5/2/23.
//

#ifndef INHERITANCE_RECTANGLE_H
#define INHERITANCE_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double height, double width);
    virtual ~Rectangle();
    void scale(double scaleFactor);
    double area();
    double perimeter();

};


#endif //INHERITANCE_RECTANGLE_H
