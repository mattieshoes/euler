// The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 
// 134217728=8^9, is a ninth power.
// 
// How many n-digit positive integers exist which are also an nth power?

// So clearly the base must be under 10, because 10^n is always n+1 digits
// So the largest is 9^n.  9^22 yields a 21-digit number...
// So [1-9]^[1-22]?  
// That's less than 200 possibilities to try.
// ... Ah, max unsigned 64 bit int is smaller than that...

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

    int count = 0;
    for(unsigned int base = 1; base < 10; base++) {
        for(unsigned int exponent = 1; exponent < 22; exponent++) {
            cl_I val = expt_pos(base, exponent);
            stringstream ss;
            ss << val;
            string val_s = ss.str();
            if(val_s.size() == exponent) {
                count++;
                cout << base << "^" << exponent << " = " << val_s << endl;
            }
        }
    }

    cout << "Count: " << count << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
