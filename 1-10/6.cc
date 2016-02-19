//The sum of the squares of the first ten natural numbers is,
// 
// 1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
//
// (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the 
// square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural numbers 
// and the square of the sum.


#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned int sumsquared = 0, squaredsum = 0;
    for (unsigned int ii = 1; ii <=100; ii++) {
        squaredsum += ii * ii;
        sumsquared += ii;
    } 
    sumsquared *= sumsquared;
    cout << "Difference is: " << sumsquared - squaredsum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
