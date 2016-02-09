// Surprisingly there are only three numbers that can be written as the sum of fourth powers 
// of their digits:
// 
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// As 1 = 1^4 is not a sum it is not included.
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.


// lower bound is 10 since "single values aren't sums"
// need upper bound.
// The most a number can add is 9^5 = 59,049
// 2 digit - 118,098
// 3 digit - 177,147
// 4 digit - 236,196
// 5 digit - 295,245
// 6 digit - 354,294
// So certainly by 354,294, we can't have a sum of powers of digits that's greater
// than the number itself

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;

int sum_pow_digits(int n, int pow) {
    stringstream ss;
    ss << n;
    string n_str = ss.str();
    int sum = 0;
    for (unsigned int ii=0; ii < n_str.size(); ii++) {
        int val = n_str[ii] - '0';
        int product = val;
        for (int jj = 1; jj < pow; jj++) 
            product *= val;
        sum += product;
    }
    return sum;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long sum = 0;
    for (int ii = 10; ii < 354294; ii++) {
        if (ii == sum_pow_digits(ii, 5))
            sum += ii;
    }
    cout << "Sum: " << sum << endl; 

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
