// A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions 
// with denominators 2 to 10 are given:
// 
// 1/2 =   0.5
// 1/3 =   0.(3)
// 1/4 =   0.25
// 1/5 =   0.2
// 1/6 =   0.1(6)
// 1/7 =   0.(142857)
// 1/8 =   0.125
// 1/9 =   0.(1)
// 1/10    =   0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 
// has a 6-digit recurring cycle.
// 
// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its 
// decimal fraction part.

#include <iostream>
#include <chrono>
#include <vector>
#include <map>

using namespace std;

int remainder(int numerator, int denominator) {
    while(numerator > denominator)
        numerator -= denominator;
    return numerator;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();
    
    int best_val = 0;
    int best_iter = 0; 
    for (int val = 1; val <= 1000; val++) {
        map<int,int> remainders;
        int r = 1;
        for(int iter = 0; ; iter++) {
            r = remainder(r*10, val);
            if(remainders.count(r) > 0) {
                int result = iter - remainders[r];
                if(result > best_iter) {
                    cout << "Val: " << val << "  iter: " << result << endl;
                    best_iter = result;
                    best_val = val;
                }
                break;
                
            }
            else {
                remainders[r] = iter;
            }
        }
        
    } 

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
