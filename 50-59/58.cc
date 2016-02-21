// Starting with 1 and spiralling anticlockwise in the following way, a square spiral with 
// side length 7 is formed.
// 
// 37 36 35 34 33 32 31
// 38 17 16 15 14 13 30
// 39 18  5  4  3 12 29
// 40 19  6  1  2 11 28
// 41 20  7  8  9 10 27
// 42 21 22 23 24 25 26
// 43 44 45 46 47 48 49
// 
// It is interesting to note that the odd squares lie along the bottom right diagonal, but 
// what is more interesting is that 8 out of the 13 numbers lying along both diagonals are 
// prime; that is, a ratio of 8/13 ≈ 62%.
// 
// If one complete new layer is wrapped around the spiral above, a square spiral with side 
// length 9 will be formed. If this process is continued, what is the side length of the 
// square spiral for which the ratio of primes along both diagonals first falls below 10%?

#include <iostream>
#include <chrono>
#include "../common/Prime.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    Prime p;   
 
    unsigned long long prime_count = 3;
    unsigned long long composite_count = 2;
    unsigned long long num = 9;
    unsigned long long shift = 4;
    while(prime_count * 9 >= composite_count) {
        for(int ii = 0; ii < 3; ii++) {
            num += shift;
            if(p.is_prime(num))
                prime_count++;
            else
                composite_count++;
        }
        num += shift;
        composite_count++;
        shift += 2;
    }
    cout << shift-1 << endl; 
 
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
