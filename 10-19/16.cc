// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?

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

    cl_I val = 2;
    cl_I exponent = 1000;
    cl_I answer = expt_pos(val, exponent);
    stringstream ss;
    ss << answer;
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
