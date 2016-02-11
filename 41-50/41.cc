// We shall say that an n-digit number is pandigital if it makes use of all 
// the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital 
// and is also prime.
// 
// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

bool is_prime(int n) {
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    int top = sqrt(n) + 2;
    for(int a = 6; a < top; a+=6)
        for(long long b = -1; b < 2; b += 2)
            if( n % (a + b) == 0)
                return false;
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    string x[9];
    x[8] = "1";
    x[7] = "21";
    x[6] = "321";
    x[5] = "4321";
    x[4] = "54321";
    x[3] = "654321";
    x[2] = "7654321";
    x[1] = "87654321";
    x[0] = "987654321";
    bool found = false;
    for(int ii=0; !found; ii++) {
        do {
            int n = stoi(x[ii]);
            if (is_prime(n)) {
                found = true;
                cout << n << endl;
                break;
            }
        } while(prev_permutation(x[ii].begin(), x[ii].end()));
    }

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
