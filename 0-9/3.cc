// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?
//
// TODO: effeciently build factor list?

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

vector<unsigned long long> naive_factor(unsigned long long n) {
    vector<unsigned long long> factors; 
    for (unsigned long long d = 2; d < n/2; d++) {
        if (n%d == 0) {
            factors.push_back(d);
            n /= d;
            vector<unsigned long long> subfactors = naive_factor(n);
            factors.insert(factors.end(), subfactors.begin(), subfactors.end());
            return factors;
        }
    }
    factors.push_back(n);
    return factors;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long val = 600851475143ULL;
    vector<unsigned long long> factors = naive_factor(val);

    unsigned long long largest = 0;
    for (unsigned int ii = 0; ii < factors.size(); ii++)
        if(factors[ii] > largest)
            largest = factors[ii];
    cout << largest << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
