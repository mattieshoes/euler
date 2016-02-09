// Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:
// 
// 2^2=4, 2^3=8, 2^4=16, 2^5=32
// 3^2=9, 3^3=27, 3^4=81, 3^5=243
// 4^2=16, 4^3=64, 4^4=256, 4^5=1024
// 5^2=25, 5^3=125, 5^4=625, 5^5=3125
// If they are then placed in numerical order, with any repeats removed, we get the 
// following sequence of 15 distinct terms:
// 
// 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
// 
// How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

// Is there an elegant way? Seems easy enough to brute force...
 
#include <iostream>
#include <chrono>
#include <set>
#include <cln/integer.h>
#include <cln/integer_io.h>

#define MAGIC 100

using namespace std;

int main () {
    using namespace std::chrono;
    using namespace cln;
    system_clock::time_point start = system_clock::now();

    set<cl_I> answers;
    for(cl_I a = 2; a <= MAGIC; a++) {
        for(cl_I b = 2; b <= MAGIC; b++) {
            cl_I n = expt_pos(a, b);
            answers.insert(n);
            
        }
    } 
    cout << "Terms: " << answers.size() << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
