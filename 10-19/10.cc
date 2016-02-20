// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// 
// Find the sum of all the primes below two million.

#include <iostream>
#include <chrono>
#include "../common/Prime.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    Prime p;
    while (p.sieve_start < 2000000)
        p.do_sieve();

    unsigned long long sum = 0;
    for(unsigned int ii = 0; ii < p.primes.size(); ii++) {
        if(p.primes[ii] >= 2000000)
            break;
        sum += p.primes[ii];
    }
    cout << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
