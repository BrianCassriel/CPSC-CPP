//
// Created by Brian Cassriel on 5/2/23.
//

#ifndef INHERITANCE_SHAPE_H
#define INHERITANCE_SHAPE_H

#include <string>

class Shape {
public:
    Shape(double height, double width);
    virtual ~Shape();
    virtual void scale(double scaleFactor) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void displayProperties();

protected:
    double height;
    double width;
    std::string type;

};


#endif //INHERITANCE_SHAPE_H
