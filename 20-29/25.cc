// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cln/integer.h>
#include <cln/integer_io.h>


using namespace std;

int main () {
    using namespace std::chrono;
    using namespace cln;
    system_clock::time_point start = system_clock::now();

    cl_I cur = 1;
    cl_I val = 1;
    cl_I prev = 1;
    cl_I index = 2;

    while(true) {
        index++;
        cur = val + prev;
        stringstream ss;
        ss << cur;
        int digits = ss.str().size();
        if(digits >= 1000) {
            cout << index << endl;
            break;
        }
        prev = val;
        val = cur;
    }
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
