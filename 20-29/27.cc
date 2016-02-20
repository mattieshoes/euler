// Euler discovered the remarkable quadratic formula:
// 
// n² + n + 41
// 
// It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. 
// However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when 
// n = 41, 41² + 41 + 41 is clearly divisible by 41.
// 
// The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the 
// consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
// 
// Considering quadratics of the form:
// 
// n² + an + b, where |a| < 1000 and |b| < 1000
// 
// where |n| is the modulus/absolute value of n
// e.g. |11| = 11 and |−4| = 4
// Find the product of the coefficients, a and b, for the quadratic expression that produces 
// the maximum number of primes for consecutive values of n, starting with n = 0.
 
#include <iostream>
#include <chrono>

using namespace std;

bool is_prime(long long n) {
    if (n < 2)
        return false;
    for (long long ii = 2; ii < n/2; ii++) {
        if( n % ii == 0)
            return false;
    }
    return true;
}

long long sequence(long long a, long long b) {
    for(long long seq = 0; ;seq++) {
        if(!is_prime(seq * seq + a * seq + b)) {
            return seq;
        }
    }
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    long long best_val[2];
    long long best_seq = 0;
   
    for(long long a = -999; a < 1000; a++) {
        for (long long b = -999; b < 1000; b++) {
            long long seq = sequence(a, b);
            if(seq > best_seq) {
                best_val[0] = a;
                best_val[1] = b;
                best_seq = seq;
                cout << best_val[0] << ", " << best_val[1] << ": " << seq << endl;
                cout << best_val[0] * best_val[1] << endl;
            }
        }
    } 
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
