// A palindromic number reads the same both ways. 
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindromic(int n) {
    stringstream ss;
    ss << n;
    string forwards = ss.str();
    string backwards = forwards;
    reverse(backwards.begin(), backwards.end());
    if(forwards == backwards)
        return true;
    return false; 
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int max_palindromic = 0;
    for (int ii=999; ii > 99; ii--) {
        for (int jj=999; jj > 99; jj--) {
            int product = ii * jj;
            if(product <= max_palindromic)
                break;
            if(is_palindromic(product)) {
                max_palindromic = product;
                break;
            }
        }
    }
    cout << "Maximum palindromic product of two three digit numbers: " << max_palindromic << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
