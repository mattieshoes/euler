// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!

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

    cl_I val = 1;
    for (int ii = 2; ii <= 100; ii++) 
        val *= ii;

    stringstream ss;
    ss << val;
    string ans_string = ss.str();

    int sum = 0;
    for (unsigned int ii = 0; ii < ans_string.size(); ii++) {
        int n = stoi(ans_string.substr(ii,1));
        sum += n;
    }
    cout << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
