// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// 
// Find the sum of all the primes below two million.

#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    bool is_prime[2000000];
    fill(is_prime, is_prime + 2000000, true);
    is_prime[0] = false; 
    is_prime[1] = false;
    
    for (int ii = 0; ii < 1415; ii++) { // sqrt(2e6) ~ 1414
        if(is_prime[ii]) {
            for (int jj = ii * 2; jj < 2e6; jj += ii) {
                is_prime[jj] = false;
            }
        }
    }
    unsigned long long sum = 0;
    for (int ii=0; ii < 2000000; ii++)
        if (is_prime[ii])
            sum += ii;

    cout << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
