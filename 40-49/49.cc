// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
// is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 
// 4-digit numbers are permutations of one another.
// 
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting 
// this property, but there is one other 4-digit increasing sequence.
// 
// What 12-digit number do you form by concatenating the three terms in this sequence?

#include <iostream>
#include <chrono>
#include "../common/Prime.h"
#include "../common/Common.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    Prime p;
    while(p.primes[p.primes.size()-1] < 10000)
        p.do_sieve();

    for (unsigned int ii = 0; ii < p.primes.size(); ii++) {
        if(p.primes[ii] < 1000)
            continue;
        for (unsigned int jj = ii + 1; jj < p.primes.size(); jj++) {
            if(p.primes[jj] > 9999)
                break;
            if(is_decimal_permutation(p.primes[ii], p.primes[jj])) {
                for (unsigned int kk = jj + 1; kk < p.primes.size(); kk++) {
                    if(p.primes[kk] > 9999)
                        break;
                    if(is_decimal_permutation(p.primes[ii], p.primes[kk])) {
                        if( p.primes[kk] - p.primes[jj] == p.primes[jj] - p.primes[ii])
                            cout << p.primes[ii] << " " 
                                 << p.primes[jj] << " " 
                                 << p.primes[kk] << endl;
                    }
                }
            }
        }
        
    }

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
