// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n 
// exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
// 
// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, 
// multiplier, and product is 1 through 9 pandigital.
// 
// Find the sum of all products whose multiplicand/multiplier/product identity can be written 
// as a 1 through 9 pandigital.
// 
// HINT: Some products can be obtained in more than one way so be sure to only include it 
// once in your sum.


// All possibilities have 9 total digits
// 2 digit x 2 digit = 4 at most, so no.
// 3 digit x 2 digit = 4-5 digit, so maybe
// 4 digit x 1 digit = 4-5 digit, so maybe
// 5 digit x 1 digit = 5 digit, so no.

// all numbers will not have 0
// all numbers will not have duplicates
// the product will be <= 9876
// easy to weed out obvious failure numbers quickly then brute force the remainder

#include <iostream>
#include <chrono>
#include <vector>
#include <set>

using namespace std;

bool maybe_valid(int n) {
    vector<int> digits;
    while (n > 10) {
        int r = n%10;
        if(r == 0)
            return false;
        digits.push_back(r);
        n /= 10;
    }
    digits.push_back(n);
    for (unsigned int ii = 0; ii < digits.size() ; ii++) {
        for (unsigned int jj = ii + 1; jj < digits.size(); jj++) {
            if(digits[ii] == digits[jj])
                return false;
        }
    }
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    set<int> products;
    for (int ii = 123; ii <= 987; ii++) {
        if(!maybe_valid(ii))
            continue;
        for (int jj = 12; jj < 98; jj++) {
            if(!maybe_valid(jj))
                continue;
            int kk = ii * jj;
            if(kk > 9876)
                continue;
            if(!maybe_valid(kk))
                continue;
            int combo = ii * 1000000 + jj * 10000 + kk;
            if(maybe_valid(combo)) {
                cout << ii << " * " << jj << " = " << kk << endl;
                products.insert(kk);
            }
        }
    }
    for (int ii = 1234; ii <= 9876; ii++) {
        if(!maybe_valid(ii))
            continue;
        for (int jj = 1; jj <= 9; jj++) {
            if(!maybe_valid(jj))
                continue;
            int kk = ii * jj;
            if(kk > 9876)
                continue;
            if(!maybe_valid(kk))
                continue;
            int combo = ii * 100000 + jj * 10000 + kk;
            if(maybe_valid(combo)) {
                cout << ii << " * " << jj << " = " << kk << endl;
                products.insert(kk);
            }
        }
    }
   
    int sum = 0;
    for(set<int>::iterator it = products.begin(); it != products.end(); it++)
        sum += *it;
    cout << "Sum of unique products: " << sum << endl;
    

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
