
#include <iostream>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <cln/integer.h>
#include <cln/integer_io.h>
#include "../common/Common.h"

using namespace std;
using namespace cln;


bool lychrel(cl_I val, int depth) {
    if(depth == 50)
        return true;
    stringstream ss;
    ss << val;
    string s = ss.str();
    if(depth > 0 && is_palindrome(s))
            return false;
    reverse(s.begin(), s.end());
    cl_I val_rev = s.c_str();
    return lychrel(val + val_rev, depth + 1);
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int count = 0;
    for(cl_I val = 1; val < 10000; val++)
        if(lychrel(val, 0)) {
            count++;
            cout << val << endl;
        }

    cout << "Count: " << count << endl;
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
