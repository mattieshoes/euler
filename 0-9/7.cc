// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 
// 6th prime is 13.
//
// What is the 10,001st prime number?

#include <iostream>
#include <chrono>
#include "../common/Prime.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    Prime p;
    while (p.primes.size() < 10001)
        p.do_sieve();

    cout << "Prime number 10,001 is: " << p.primes[10000] << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
