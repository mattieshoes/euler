// An irrational decimal fraction is created by concatenating the 
// positive integers:
// 
// 0.123456789101112131415161718192021...
// 
// It can be seen that the 12th digit of the fractional part is 1.
// 
// If dn represents the nth digit of the fractional part, find the value 
// of the following expression.
// 
// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000


#include <iostream>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    string n = "";
    int val = 1;
    while (n.size() < 1000000) {
        stringstream ss;
        ss << val;
        n += ss.str();
        val++;
    }
    int result =    (int) (n[0] - '0') * 
                    (int) (n[9] - '0') * 
                    (int) (n[99] - '0') * 
                    (int) (n[999] - '0') * 
                    (int) (n[9999] - '0') * 
                    (int) (n[99999] - '0') * 
                    (int) (n[999999] - '0');
    cout << "Result: " << result << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
