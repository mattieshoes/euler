// Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine 
// the number of numbers less than n which are relatively prime to n. For example, as 
// 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
// 
// n   Relatively Prime    φ(n)    n/φ(n)
// 2   1                   1       2
// 3   1,2                 2       1.5
// 4   1,3                 2       2
// 5   1,2,3,4             4       1.25
// 6   1,5                 2       3
// 7   1,2,3,4,5,6         6       1.1666...
// 8   1,3,5,7             4       2
// 9   1,2,4,5,7,8         6       1.5
// 10  1,3,7,9             4       2.5
// It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
// 
// Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

// Answer is the product of all primes that has a result under a million
// 2 * 3 * 5 * 7 * 11 * 13 * 17 = 510,510.  
// Calculating phi for every number way too slow...
// Used sieve method to calculate phi for all numbers simultaneously

#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    double *phi = new double[1000001];
    for (int ii = 1; ii <= 1000000; ii++)
        phi[ii] = ii;
    for (int ii = 2; ii <= 1000000; ii++) 
        if (phi[ii] == ii) // prime
            for (int jj = ii; jj <= 1000000; jj += ii)
                phi[jj] = phi[jj] * (ii-1)/ii;
    int best_index = 1;
    double best_ratio = 1;
    for (int ii=2; ii <= 1000000; ii++) {
        double ratio = ii / phi[ii];
        if (ratio  > best_ratio) {
            best_ratio = ratio;
            best_index = ii;
        }
    }
    cout << best_index << ": " << best_ratio << endl;
    delete[] phi;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
