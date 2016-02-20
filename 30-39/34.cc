// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
// 
// Find the sum of all numbers which are equal to the sum of the factorial 
// of their digits.
// 
// Note: as 1! = 1 and 2! = 2 are not sums they are not included.

// 9999999 -> 2540160

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    unsigned long long sum = 0;
    for (int ii = 10; ii < 9999999; ii++) {
        int jj = ii;
        int numsum = 0;
        while (jj >= 10) {
           numsum += fact[jj % 10];
           jj /= 10;
        }
        numsum += fact[jj];
        if(numsum == ii) {
            sum += numsum;
            cout << ii << " : " << sum << endl;
        }
    }


    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
