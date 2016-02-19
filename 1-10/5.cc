// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without 
// any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the numbers 
// from 1 to 20?

// Max answer will be 20! / 10! which is less than 2^64

#include <iostream>
#include <chrono>

using namespace std;

unsigned long long minimum_common_multiple (unsigned long long n) {
    if (n == 1)
        return 1;
    unsigned long long step = minimum_common_multiple(n-1);
    unsigned long long mcm = step;
    while (mcm % n != 0)
        mcm += step;
    return mcm;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long mcm = minimum_common_multiple(20ULL);
    cout << mcm << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
