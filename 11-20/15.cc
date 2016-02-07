// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and 
// down, there are exactly 6 routes to the bottom right corner.
//
// How many such routes are there through a 20×20 grid?

// So it will always move right 20 times and down 20 times.  
// So 40! for the exact order, divided by 20! for all the permutations of downs, 
// divided by 20! for all the permutations of rights... 40! / (20! * 20!)
// initially solved here: https://www.google.com/search?q=40!+%2F+(20!+*+20!)

#include <iostream>
#include <chrono>
#include <cln/integer.h>
#include <cln/integer_io.h>

using namespace std;

int main () {
    using namespace std::chrono;
    using namespace cln;
    system_clock::time_point start = system_clock::now();

    cl_I forty_factorial = factorial(40);
    cl_I twenty_factorial = factorial(20);
    cl_I result = exquo(forty_factorial, (twenty_factorial * twenty_factorial));
    cout << result << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
