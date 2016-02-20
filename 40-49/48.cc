// The series, 11 + 22 + 33 + ... + 1010 = 10405071317.
//
// Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
 
#include <iostream>
#include <chrono>
#include <cln/integer.h>
#include <cln/integer_io.h>

using namespace std;

int main () {
    using namespace std::chrono;
    using namespace cln;
    system_clock::time_point start = system_clock::now();

    cl_I sum = 0;
    for(cl_I n = 1; n <= 1000; n++) {
      sum += expt_pos(n, n); 
    }
    cout << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
