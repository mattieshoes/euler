// The number 3797 has an interesting property. Being prime itself, it is 
// possible to continuously remove digits from left to right, and remain 
// prime at each stage: 3797, 797, 97, and 7. Similarly we can work from 
// right to left: 3797, 379, 37, and 3.
// 
// Find the sum of the only eleven primes that are both truncatable from 
// left to right and right to left.
// 
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 
#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

unsigned long long truncate_left(unsigned long long n) {
    unsigned long long mod = 1;
    while(mod < n)
        mod *= 10;
    mod /= 10;
    return n % mod;
}

unsigned long long truncate_right(unsigned long long n) {
    return n / 10;
}

bool is_prime(unsigned long long n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n == 3)
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

bool truncatable_prime(unsigned long long n) {
    if(!is_prime(n))
        return false;
    unsigned long long m = truncate_left(n);
    while(m > 0) {
        if(!is_prime(m))
            return false;
        m = truncate_left(m);
    }
    m = truncate_right(n);
    while (m > 0) {
        if(!is_prime(m))
            return false;
        m = truncate_right(m);
    }
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int count = 0;
    unsigned long long sum = 0;
    for (unsigned long long a = 12; ; a += 6) {
        for(long long b = -1; b < 2; b += 2) {
            if(truncatable_prime(a+b)) {
                count++;
                sum += (a+b);
                cout << count << ": " << a+b << endl;
                if(count == 11)
                    break;
            }
        }
        if(count == 11)
            break;
    }
    cout << "Sum: " << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
