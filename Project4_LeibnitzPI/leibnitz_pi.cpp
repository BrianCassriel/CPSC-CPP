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
    
    cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz formula of computing pi: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        pi += (pow(-1, i))/(2*i + 1);
    }
    pi *= 4;
    cout << fixed << setprecision(__DBL_DIG__) << pi << endl;
    cout << "3.141592653589793" << endl;
    
    cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << __DBL_DIG__ << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: "
              <<  __DBL_MANT_DIG__ << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
    
    return 0;
}
