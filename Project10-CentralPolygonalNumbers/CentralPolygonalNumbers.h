//
// Created by Brian Cassriel on 4/18/23.
//
#include <iostream>
#ifndef CENTRALPOLYGONALNUMBERS_CENTRALPOLYGONALNUMBERS_H
#define CENTRALPOLYGONALNUMBERS_CENTRALPOLYGONALNUMBERS_H


class CentralPolygonalNumbers {
public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    bool save(std::string fileName);

private:
    int nMax;
    int* numbers;
    int calculateNext(int n);

};


#endif //CENTRALPOLYGONALNUMBERS_CENTRALPOLYGONALNUMBERS_H
