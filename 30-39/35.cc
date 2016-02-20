// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, 
// and 719, are themselves prime.
// 
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// 
// How many circular primes are there below one million?


#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

bool is_prime(int n) {
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    int end = sqrt(n+1); //just sidestepping floating point error for minimal cost I think
    for(int ii = 6; ii <= end + 1; ii += 6) {
        if (n % (ii - 1) == 0)
            return false;
        if (n % (ii + 1) == 0)
            return false;
    }
    return true;
}

bool all_digits_odd(int n) {
    while (n > 1) {
        int r = n % 10;
        n /= 10;
        if(r % 2 == 0)
            return false;
    }
    return true;
}

int rotate(int n) {
    int r = n % 10;
    n /= 10;
    int mult = 1;
    while(mult <= n)
        mult *= 10;
    n += r * mult;
    return n;
}


int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();
    
    unsigned long long count = 2; //2 and 3
    cout << 2 << endl << 3 << endl;
    for (int ii = 6; ii < 1000000; ii += 6) {
        for(int jj = -1; jj < 2; jj+= 2) {
            int n = ii + jj;
            if(!all_digits_odd(n))
                continue;
            if(!is_prime(n))
                continue;
            int rot = 0;
            int tmpn = n;
            while(tmpn > 10) {
                rot++;
                tmpn /= 10;
            }
            bool all_prime = true;
            tmpn = n;
            while(rot > 0) {
                tmpn = rotate(tmpn);
                rot--;
                if(!is_prime(tmpn)) {
                    all_prime = false;
                    break;
                }
            }
            if(all_prime) {
                cout << n << endl;
                count++;
            }
        }
    }
    cout << "Count: " << count << endl;
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
