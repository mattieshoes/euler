// The following iterative sequence is defined for the set of positive integers:
//
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence:
//
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
// Although it has not been proved yet (Collatz Problem), it is thought that all starting 
// numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
// 
// NOTE: Once the chain starts the terms are allowed to go above one million.
//
// TODO: cache results of already-calculated chains, since they can't deviate
#include <iostream>
#include <chrono>

using namespace std;

unsigned long long collatz(unsigned long long value) {
    if (value == 1)
        return 1;
    if (value % 2 == 0)
        return collatz(value/2) + 1;
    return collatz(value*3+1) + 1;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long longest_chain = 1;
    unsigned long long longest_chain_start = 1;
    for(unsigned long long val = 2; val < 1000000; val++) {
        unsigned long long chain = collatz(val);
        if(chain > longest_chain) {
            longest_chain = chain;
            longest_chain_start = val;
        }
    }
    cout << longest_chain_start << ": " << longest_chain << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
