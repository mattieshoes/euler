// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 
// 6th prime is 13.
//
// What is the 10,001st prime number?

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<int> primes;
    bool is_prime = false;
    for (unsigned int val = 2; ; val++) {
        is_prime = true;
        for (unsigned int ii=0; ii < primes.size(); ii++) {
            if (val % primes[ii] == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) {
            primes.push_back(val);
            if(primes.size() == 10001U)
                break;
        }
    }    
    cout << "Prime number 10,001 is: " << primes[primes.size()-1] << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
