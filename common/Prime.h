#ifndef PRIME_H
#define PRIME_H

#include <vector>

class Prime {
  public:
    Prime();
    unsigned long long next();
    unsigned long long isqrt(unsigned long long n);
    std::vector<unsigned long long> primes;
    void do_sieve();
  private:
    unsigned long long index;
    std::vector<bool> sieve;
    static const unsigned int sieve_size = 1000;
    unsigned long long sieve_start;
    
};

#endif
