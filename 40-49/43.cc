// The number, 1406357289, is a 0 to 9 pandigital number because it is made 
// up of each of the digits 0 to 9 in some order, but it also has a rather 
// interesting sub-string divisibility property.
// 
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, 
// we note the following:
// 
// d2d3d4=406 is divisible by 2
// d3d4d5=063 is divisible by 3
// d4d5d6=635 is divisible by 5
// d5d6d7=357 is divisible by 7
// d6d7d8=572 is divisible by 11
// d7d8d9=728 is divisible by 13
// d8d9d10=289 is divisible by 17
// Find the sum of all 0 to 9 pandigital numbers with this property.

#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long sum = 0;
    string pan = "1023456789";
    do {
        if(stoi(pan.substr(1,3)) % 2 == 0)
            if(stoi(pan.substr(2,3)) % 3 == 0)
                if(stoi(pan.substr(3,3)) % 5 == 0)
                    if(stoi(pan.substr(4,3)) % 7 == 0)
                        if(stoi(pan.substr(5,3)) % 11 == 0)
                            if(stoi(pan.substr(6,3)) % 13 == 0)
                                if(stoi(pan.substr(7,3)) % 17 == 0){
                                    cout << pan << endl;
                                    sum += stoull(pan);
                                }
    } while(next_permutation(pan.begin(), pan.end()));

    cout << "Sum: " << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
