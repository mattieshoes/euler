// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.


#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int answer = 0;
    for (int a = 1; a < 1000; a++) {
        for (int b = 1; b+a < 1000; b++) {
            int c = 1000 - a - b;
            if(a*a + b*b == c*c)
               answer = a*b*c; 
        }
        if(answer)
            break;
    }
    
    cout << answer << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
