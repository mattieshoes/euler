// The first known prime found to exceed one million digits was discovered in 1999, and is a 
// Mersenne prime of the form 2^6972593−1; it contains exactly 2,098,960 digits. Subsequently 
// other Mersenne primes, of the form 2p−1, have been found which contain more digits.
// 
// However, in 2004 there was found a massive non-Mersenne prime which contains 
// 2,357,207 digits: 28433×27830457+1.
// 
// Find the last ten digits of this prime number.


#include <iostream>
#include <chrono>
#include <cln/integer.h>
#include <cln/integer_io.h>
#include <sstream>

using namespace std;

int main () {
    using namespace std::chrono;
    using namespace cln;
    system_clock::time_point start = system_clock::now();

    cl_I result = expt_pos(2, 7830457);
    result *= 28433;
    result++;

    stringstream ss;
    ss << result;
    string snum = ss.str(); 

    cout << snum.substr(snum.size()-10,10) << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
