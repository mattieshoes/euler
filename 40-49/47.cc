// The first two consecutive numbers to have two distinct prime factors are:
// 
// 14 = 2 × 7
// 15 = 3 × 5
// 
// The first three consecutive numbers to have three distinct prime factors are:
// 
// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.
// 
// Find the first four consecutive integers to have four distinct prime factors. 
// What is the first of these numbers?

#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

bool is_prime(unsigned long long n) {
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    unsigned long long top = sqrt(n) + 2;
    for(unsigned long long a = 6; a < top; a+=6)
        for(long long b = -1; b < 2; b += 2)
            if( n % (a + b) == 0)
                return false;
    return true;
}

unsigned long long next_prime(vector<unsigned long long> &v) {
    unsigned long long n = v[v.size()-1] + 2;
    while(!is_prime(n))
        n += 2;
    return n;
}

void push_numbers(unsigned long long current, vector<unsigned long long> &f, 
                  unsigned long long index, set<unsigned long long> &numbers, 
                  unsigned long long max) {
    if(current > max)
        return;
    numbers.insert(current);
    if(current == 113707) {
        cout << "Current: " << current << endl;
        cout << "f[0]: " << f[0] << endl;
        cout << "f[1]: " << f[1] << endl;
        cout << "f[2]: " << f[2] << endl;
        cout << "f[3]: " << f[3] << endl;
        cout << "Index: " << index << endl;
        string q;
        cin >> q;
    }
    for(unsigned long long ii = index; ii < f.size(); ii++) {
        unsigned long long  val = current * f[ii];
        if(val < max)
            push_numbers(val, f, ii, numbers, max);
    }
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<unsigned long long> primes = {2, 3, 5};
    set<unsigned long long> numbers;
    unsigned long long max = 200000;
    bool found = false;
    while (!found) {
        int val = next_prime(primes);
        cout << "looking at " << val << endl;
        for (unsigned int a = 0; a < primes.size(); a++) {
            for (unsigned int b = a + 1; b < primes.size(); b++) {
                for (unsigned int c = b + 1; c < primes.size(); c++) {
                    unsigned long long cur = primes[a] * primes[b] * primes[c] * val;
                    if(cur < max) {
                        vector<unsigned long long> factor_list;
                        factor_list.push_back(primes[a]);
                        factor_list.push_back(primes[b]);
                        factor_list.push_back(primes[c]);
                        factor_list.push_back(val);
                        push_numbers(cur, factor_list, 0, numbers, max);               
                    }
                    else
                        break;
                }
            }
        }
        primes.push_back(val);
        for(set<unsigned long long>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            int num = *it;
            if(numbers.count(num+1) > 0 && numbers.count(num+2) > 0 && numbers.count(num+3) > 0) {
                cout << num << " and the next 3 are in the list" << endl;
                found = true;
                break;
            }
        }
    } 

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
