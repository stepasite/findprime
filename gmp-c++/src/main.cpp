#include <iostream>
#include <chrono>
#include <ctime>
#include <gmpxx.h>

int isprime(int e) {
    auto t1 = std::chrono::system_clock::now();
    mpz_class mp((mpz_class(1) << e) - 1);
    int result = mpz_probab_prime_p (mp.get_mpz_t(), 1);
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = t2 - t1;
    double elapsedHours = elapsedSeconds.count() / 60 / 60;
    std::cout << "Running time in hours: " << elapsedHours << std::endl;
    return result;
}

int main() {
    int exponent = 82589933;
    std::cout << "The candidate Mersenne prime is: 2^" << exponent << " - 1" << std::endl;
    bool ismp = isprime(exponent);
    std::cout << "The candidate is Mersenne prime: " << ismp << std::endl;
}
