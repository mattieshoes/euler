// Comparing two numbers written in index form like 211 and 37 is not difficult, as any 
// calculator would confirm that 211 = 2048 < 37 = 2187.
// 
// However, confirming that 632382518061 > 519432525806 would be much more difficult, as both 
// numbers contain over three million digits.
// 
// Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing 
// one thousand lines with a base/exponent pair on each line, determine which line number has 
// the greatest numerical value.
// 
// NOTE: The first two lines in the file represent the numbers in the example given above.

// log(x^y) = y * log(x) 

#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    ifstream f ("99.txt");
    string field;
    double most = 0;
    int most_line_number = 0;
    if(f.is_open()) {
        for (int ii = 0; ii < 1000; ii++) {
            getline(f, field, ',');
            int base = stoi(field);
            getline(f, field);
            int exponent = stoi(field);
            double val = log(base) * exponent;
            if(val > most) {
                most = val;
                most_line_number = ii + 1;
            }
        }
    } else {
        cout << "Couldn't open 99.txt" << endl;
        return 1;
    }

    cout << most_line_number << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
