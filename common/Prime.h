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
    unsigned long long sieve_start;
    bool is_prime(unsigned long long n);
  private:
    unsigned long long index;
    std::vector<bool> sieve;
    static const unsigned int sieve_size = 1000;
    
};

#endif
