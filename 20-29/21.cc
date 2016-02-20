// Let d(n) be defined as the sum of proper divisors of n 
// (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b 
// are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
// therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int sum_proper_divisors(int n) {
    int sum = 1;
    int top = n / 2;
    for (int ii = 2; ii < top; ii++) {
        if ( n % ii == 0) {
            sum += ii;
            int val = n / ii;
            if ( val != ii)
                sum += val;
            top = val;
        }
    }
    return sum;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<int> divisors;
    divisors.push_back(0);
    divisors.push_back(0);

    for (int ii = 2; ii < 10000; ii++)
        divisors.push_back(sum_proper_divisors(ii));

    int sum = 0;
    for (int ii = 2; ii < 10000; ii++) {
        if (divisors[ii] > 10000 || divisors[ii] == ii)
            continue;
        if (divisors[divisors[ii]] == ii)
            sum += ii;
    }

    cout << "Sum of amicable numbers under 10,000: " << sum << endl;


    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
