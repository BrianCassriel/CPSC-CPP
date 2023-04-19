//
// Created by Brian Cassriel on 4/18/23.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include "CentralPolygonalNumbers.h"
using namespace std;

CentralPolygonalNumbers::CentralPolygonalNumbers() {
    nMax = 0;
    numbers = new int[1];
    numbers[0] = 1;
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) {
    this->nMax = nMax;
    numbers = new int[nMax + 1];
    for (int n = 0; n <= nMax; n++) {
        numbers[n] = calculateNext(n);
    }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers() {
    delete[] numbers;
    cout << "~CentralPolygonalNumbers called" << endl;
}

void CentralPolygonalNumbers::display() {
    for (int n = 0; n <= nMax; n++) {
        cout << n << ": maximum number of pieces: " << numbers[n] << endl;
    }
}

int CentralPolygonalNumbers::calculateNext(int n) {
    return (pow(n, 2) + n + 2) / 2.0;
}

bool CentralPolygonalNumbers::save(string fileName) {
    ofstream ofsNumbers;
    ofsNumbers.open(fileName);
    for (int n = 0; n <= nMax; n++) {
        ofsNumbers << numbers[n] << endl;
    }
    ofsNumbers.close();
}
