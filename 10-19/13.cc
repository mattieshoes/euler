// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
//
// 13.txt 

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

    cl_I val, sum = 0;

    ifstream numberfile ("13.txt");
    if (numberfile.is_open()) {
        string line;
        for (int ii = 0; ii < 100; ii++) {
            getline(numberfile, line);
            stringstream ss(line);
            ss >> val;
            sum += val;
        }
        numberfile.close();
    }
    
    stringstream ss;
    ss << sum;
    cout << ss.str().substr(0,10) << endl;
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
