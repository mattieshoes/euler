// Take the number 192 and multiply it by each of 1, 2, and 3:
// 
// 192 × 1 = 192
// 192 × 2 = 384
// 192 × 3 = 576
// By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 
// 192384576 the concatenated product of 192 and (1,2,3)
// 
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the 
// pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
// 
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated i
// product of an integer with (1,2, ... , n) where n > 1?


#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

unsigned long long concatenate(unsigned long long a, unsigned long long b) {
    unsigned long long mult = 1;
    while (mult < b)
        mult *= 10;
    return a * mult + b;;
}
bool precheck(unsigned long long n) {
    if(n >= 1000000000)
        return false;
    vector<int> digits;
    while(n > 0) {
        int d = n % 10;
        if(d == 0)
            return false;
        digits.push_back(d);
        n /= 10;
    }
    for (unsigned int aa = 0; aa < digits.size(); aa++)
        for (unsigned int bb = aa + 1; bb < digits.size(); bb++)
            if (digits[aa] == digits[bb])
                return false;
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long max = 0;
    for (unsigned long long ii = 1; ii < 10000; ii++) {
        if(!precheck(ii))
            continue;
        unsigned long long concat = ii;
        for(int jj = 2; ; jj++) {
            concat = concatenate(concat, ii*jj);
            if(!precheck(concat))
                break;
            if(concat > 100000000) {
                if(concat > max) 
                    max = concat;
                cout << ii << " -> " << concat << endl;
            }
        }
    }
    cout << "Max: " << max << endl;


    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
