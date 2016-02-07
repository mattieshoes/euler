// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
// The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int sum = 0;
    for (int ii = 0; ii < 1000; ii++)
        if ((ii % 3 == 0) || (ii % 5 == 0))
            sum += ii;
    cout << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
