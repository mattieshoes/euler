// The prime 41, can be written as the sum of six consecutive primes:
// 
// 41 = 2 + 3 + 5 + 7 + 11 + 13
// This is the longest sum of consecutive primes that adds to a prime below one-hundred.
// 
// The longest sum of consecutive primes below one-thousand that adds to a prime, 
// contains 21 terms, and is equal to 953.
// 
// Which prime, below one-million, can be written as the sum of the most consecutive primes?
//
// So, fast way to calculate the sum of primes without constantly adding is to calculate
// a cumulative sum of primes, then subtract a smaller cumulative sum to get the answer


#include <iostream>
#include <chrono>
#include "../common/Prime.h"
#include "../common/Common.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    // generate primes to a million
    Prime p;
    while(p.sieve_start < 1000000)
        p.do_sieve();

    // generate cumulative sum of primes
    vector<unsigned long long> sum_primes;
    sum_primes.push_back(2);
    for(unsigned int ii = 1; ii < p.primes.size(); ii++) {
        sum_primes.push_back(sum_primes.back() + p.primes[ii]);
    }
    unsigned long long largest_sequence = 1;
    unsigned long long largest_sequence_sum = 0;
    for(unsigned int a = 0; a < sum_primes.size(); a++) {
        for (unsigned int b = a + largest_sequence; b < sum_primes.size(); b++) {
            unsigned long long sum = sum_primes[b] - sum_primes[a];
            if(sum > 1000000)
                break;
            if(p.is_prime(sum)) {
                largest_sequence = b - a;
                largest_sequence_sum = sum;
                cout << "Largest Sequence: " << largest_sequence << "(" 
                     << largest_sequence_sum << ")" << endl;
            }
        }
    }
    

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
