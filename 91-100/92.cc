// A number chain is created by continuously adding the square of the digits in a number to 
// form a new number until it has been seen before.
// 
// For example,
// 
// 44 → 32 → 13 → 10 → 1 → 1
// 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
// 
// Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is 
// most amazing is that EVERY starting number will eventually arrive at 1 or 89.
// 
// How many starting numbers below ten million will arrive at 89?
//
// The numbers devolve quickly into 1 to (9^2*7)=567 so we want to cache results from 1 to 567
// thereby removing the chaining.

#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

bool ends_at_eightynine(unsigned long long n, unordered_map<unsigned long long, bool> &partials) {
    if (partials.count(n) > 0)
        return partials[n];
    unsigned long long sum = 0;
    unsigned long long m = n;
    while (m > 0) {
        unsigned long long digit = m % 10;
        m /= 10;
        sum += digit * digit;
    }
    if(ends_at_eightynine(sum, partials))
        return true;
    else
        return false;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unordered_map<unsigned long long, bool> partials;
    partials.insert(make_pair<unsigned long long, bool>(1ULL, false));
    partials.insert(make_pair<unsigned long long, bool>(89ULL, true));
    for(unsigned long long ii = 2; ii <= 567; ii++) {
        if(ii == 89ULL)
            continue;
        if(ends_at_eightynine(ii, partials))
            partials.insert(make_pair(ii, true));
        else
            partials.insert(make_pair(ii, false));
    }

    unsigned long long count=0;
    for(unsigned long long n = 1; n < 10000000; n++)
        if(ends_at_eightynine(n, partials))
            count++;

    cout << count << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
