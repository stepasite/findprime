#include <iostream>
#include <fmpzxx.h>

bool isprime(int e) {
    flint::fmpzxx mp((flint::fmpzxx(1) << e) - 1);
    bool result = mp.is_probabprime();
    return result;
}

int main() {
    int exponent = 82589933;
    std::cout << "The candidate Mersenne prime is: 2^" << exponent << " - 1" << std::endl;
    bool ismp = isprime(exponent);
    std::cout << "The candidate is Mersenne prime: " << ismp << std::endl;
}
