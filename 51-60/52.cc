// It can be seen that the number, 125874, and its double, 251748, contain exactly the 
// same digits, but in a different order.
// 
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, 
// contain the same digits.

#include <iostream>
#include <chrono>
#include "../common/Common.h"

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();
    unsigned long long next = 10;
    for (unsigned long long aa = 1; ; aa++) {
        if(decimal_digits(aa*6) > decimal_digits(aa)){
            aa = next;
            next *= 10;
        }
        if(is_decimal_permutation(aa, aa * 2) &&
           is_decimal_permutation(aa, aa * 3) &&
           is_decimal_permutation(aa, aa * 4) &&
           is_decimal_permutation(aa, aa * 5) &&
           is_decimal_permutation(aa, aa * 6)) {
            cout << aa << endl;
            break;
        }
    }


    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
