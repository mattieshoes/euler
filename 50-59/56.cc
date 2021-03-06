// A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost 
// unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the 
// digits in each number is only 1.
// 
// Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <cln/integer.h>
#include <cln/integer_io.h>
#include "../common/Common.h"

using namespace std;
using namespace cln;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    cl_I max = 0;
    for(cl_I a = 10; a < 100; a++) {
        for(cl_I b = 10; b < 100; b++) {
            cl_I a_to_b = expt_pos(a, b);
            cl_I sum = sum_digits(a_to_b);
            if(sum > max)
                max = sum;
        }
    }  
    cout << "Maximum digital sum: " << max << endl;
 
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
