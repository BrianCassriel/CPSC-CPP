//
//  main.cpp
//  LoopingExcersize
//
//  Created by Brian Cassriel on 3/1/23.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    double pi = 0.0;
    int n = pow(2, 20);
    int doubleLast = 2;
    
    for (int i = 0; i <= n; i++) {
        pi += (pow(-1, i))/(2*i + 1);
        if (i == doubleLast) {
            cout << "PI: " << fixed << setprecision(__DBL_DIG__) << pi*4 << "; n: " << i << endl;
            doubleLast *= 2;
        }
    }
    
    return 0;
}
