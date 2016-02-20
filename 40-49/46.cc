// It was proposed by Christian Goldbach that every odd composite number can be written as 
// the sum of a prime and twice a square.
// 
// 9 = 7 + 2×1^2
// 15 = 7 + 2×2^2
// 21 = 3 + 2×3^2
// 25 = 7 + 2×3^2
// 27 = 19 + 2×2^2
// 33 = 31 + 2×1^2
// 
// It turns out that the conjecture was false.
// 
// What is the smallest odd composite that cannot be written as the sum of a 
// prime and twice a square?

#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

bool is_prime(unsigned long long n) {
    if (n == 1) 
        return false;
    if (n < 4)
        return true;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    unsigned long long top = sqrt(n) + 2;
    for(unsigned long long a = 6; a < top; a+=6)
        for(long long b = -1; b < 2; b += 2)
            if( n % (a + b) == 0)
                return false;
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    for(unsigned long long n = 9; ; n+=2) {
        if(is_prime(n))
            continue;
        bool found = false;
        for(unsigned long long s = 1; ; s++) {
            unsigned long long sq = s * s * 2;
            if(sq - 2 > n)
                break;
            if(is_prime(n - sq)) {
                found = true;
                cout << n << " = " << n - sq << " + 2 * " << s << "^2" << endl;
                break;
            }
        }
        if(!found) {
            cout << n << " has no solutions!" << endl;
            break;
        }
    }

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
