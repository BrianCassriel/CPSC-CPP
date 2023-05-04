#include <iostream>

unsigned long sigma(unsigned long n) {
    unsigned long sum;
    try {
        if (n < 1)
            throw std::runtime_error("Precondition n>=1 violated; invalid value for argument n: " + std::to_string(n)
            + " (Loc: " + __FILE__ + ":" + std::to_string(__LINE__) + ")");

        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        if (sum != (n * (n+1) / 2))
            throw std::runtime_error("Postcondition sum == (n(n+1)/2) violated; sum: " + std::to_string(sum) + "; (m(n+1)/2): " + std::to_string(n * (n+1) / 2)
            + " (Loc: " + __FILE__ + ":" + std::to_string(__LINE__) + ")");
    } catch (std::runtime_error &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        std::cout << "Could not compute sum, returning 0." << std::endl;
        return 0;
    }

    return sum;
}

int main() {
    std::cout << "sigma(5) = " << sigma(5) << std::endl;
    std::cout << "sigma(0) = " << sigma(0) << std::endl;

    return 0;
}
