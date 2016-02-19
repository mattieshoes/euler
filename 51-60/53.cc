// There are exactly ten ways of selecting three from five, 12345:
// 
// 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
// 
// In combinatorics, we use the notation, 5C3 = 10.
// 
// In general,
// 
// nCr =  n! / (r!(n−r)!)
// ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
// It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
// 
// How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are 
// greater than one-million?

#include <iostream>
#include <chrono>
#include <cln/integer.h>
#include <cln/integer_io.h>

using namespace std;

bool combination_greater_than_one_million(unsigned int n, unsigned int r) {
    using namespace cln;
    cl_I c = exquo(factorial(n), (factorial(r) * factorial(n - r)));
    if(c > 1000000)
        return true;
    return false;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int count = 0;
    for(int n = 1; n <= 100; n++) {
        for(int r = 1; r<=n; r++) {
            if(combination_greater_than_one_million(n, r))
                count++;
        }
    }
    cout << "Count: " << count << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
