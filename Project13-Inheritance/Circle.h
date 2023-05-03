//
// Created by Brian Cassriel on 5/2/23.
//

#ifndef INHERITANCE_CIRCLE_H
#define INHERITANCE_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double height, double width);
    virtual ~Circle();
    void scale(double scaleFactor);
    double area();
    double perimeter();

};


#endif //INHERITANCE_CIRCLE_H
