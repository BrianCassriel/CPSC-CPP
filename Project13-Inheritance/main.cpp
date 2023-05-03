#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

int main() {
    Rectangle* shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* shapeCircle = new Circle(2.0, 2.0);

    Shape* shapes[2];

    shapes[0] = shapeCircle;
    shapes[1] = shapeRectangle;

    for (Shape* &shape : shapes) {
        shape->displayProperties();
        std::cout << "Area: " << shape->area() << ", Perimeter: " << shape->perimeter() << std::endl;
        shape->scale(2);
        shape->displayProperties();
        std::cout << "Area: " << shape->area() << ", Perimeter: " << shape->perimeter() << std::endl << std::endl;
    }

    delete shapeRectangle;
    delete shapeCircle;
    return 0;
}
