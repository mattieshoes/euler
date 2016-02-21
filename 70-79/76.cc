// It is possible to write five as a sum in exactly six different ways:
// 
// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1
// 
// How many different ways can one hundred be written as a sum of at least two positive integers?



#include <iostream>
#include <chrono>

using namespace std;

unsigned long long ways (unsigned long long num, 
                         unsigned long long current, unsigned long long max) {
    if (current == num)
        return 1ULL;
    if(max == 1)
        return 1ULL;
    unsigned long long total = 0;
    for (unsigned long long n = max; n > 0; n--)
        if (current + n <= num)
            total += ways(num, current+n, n);
    return total; 
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    cout << ways(100ULL, 0ULL, 99ULL) << endl; 
 
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
