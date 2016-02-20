// The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
// 
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// 
// (Please note that the palindromic number, in either base, may not include leading zeros.)

// Sounds like we write is_palindromic with a base argument?


#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

bool is_palindromic(int n, int base) {
    if(base < 2)
        return false;
    vector<int> rep;
    while(n > 0) {
        rep.push_back(n%base);
        n /= base;
    }
    int start = 0;
    int end = rep.size() - 1;
    while (end > start) {
        if(rep[start] != rep[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long sum = 0;
    for(int ii = 1; ii < 1000000; ii+=2)
        if(is_palindromic(ii, 10)) 
            if(is_palindromic(ii, 2))
                sum += ii;
    cout << "Sum: " << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
