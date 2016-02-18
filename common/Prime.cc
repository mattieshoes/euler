#include "Prime.h"
#include <math.h>
#include <iostream>

using namespace std;

Prime::Prime() {
    index = 0;
    for (unsigned int ii = 0; ii < sieve_size; ii++)
        sieve.push_back(true);
    sieve[0] = false;
    sieve[1] = false;
    unsigned long long top = isqrt(sieve_size);
    for (unsigned long long ii = 2; ii <= top; ii++) {
        if(sieve[ii] == true) {
            unsigned long long jj = ii * 2;
            while (jj < sieve_size) {
                sieve[jj] = false;
                jj += ii;
            }
        }
    }
    for (unsigned long long ii = 0; ii < sieve_size; ii++)
        if (sieve[ii] == true)
            primes.push_back(ii);
    sieve_start = sieve_size;
}

unsigned long long Prime::isqrt(unsigned long long n) {
    unsigned long long r  = (unsigned long long)sqrt((double)n);
    unsigned long long rr = r * r;

    while(rr < n) {
        r++;
        rr = r * r;
    }
    while(rr > n) {
        r--;
        rr = r * r;
    }
    return r;
}

void Prime::do_sieve() {
    fill(sieve.begin(), sieve.end(), true);
    unsigned long long sieve_end = sieve_start + sieve_size;
    unsigned long long top = isqrt(sieve_end);
   
    for(unsigned long long ii = 0; primes[ii] <= top; ii++) {
        unsigned long long val = primes[ii] * (sieve_start/primes[ii]);
        while(val < sieve_start)
            val += primes[ii];
        while(val < sieve_end) {
            sieve[val-sieve_start] = false;    
            val += primes[ii];
        }
    }
    for(unsigned long long ii = 0; ii < sieve_size; ii++) {
        if(sieve[ii] == true)
            primes.push_back(ii+sieve_start);
    }
    sieve_start += sieve_size;
}

unsigned long long Prime::next() {
    while(index == primes.size())
        do_sieve();
    return primes[index++]; 
}

bool Prime::is_prime(unsigned long long n) {
    while(sieve_start < n)
        do_sieve();
    unsigned int min = 0;
    unsigned int max = primes.size();
    
    while (min < max) {
        unsigned int target = (max - min) / 2 + min;
        
        if (primes[target] < n)
            min = target + 1;
        else if (primes[target] > n)
            max = target;
        else
            return true;
    }
    return false;
}
