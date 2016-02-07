// A perfect number is a number for which the sum of its proper divisors is exactly equal to 
// the number. For example, the sum of the proper divisors of 28 would be 
// 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// 
// A number n is called deficient if the sum of its proper divisors is less than n and it is 
// called abundant if this sum exceeds n.
// 
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can 
// be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown 
// that all integers greater than 28123 can be written as the sum of two abundant numbers. 
// However, this upper limit cannot be reduced any further by analysis even though it is known 
// that the greatest number that cannot be expressed as the sum of two abundant numbers is 
// less than this limit.
// 
// Find the sum of all the positive integers which cannot be written as the sum of two 
// abundant numbers.

#include <iostream>
#include <chrono>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_abundant(int n) {
    int sum_divisors = 1;
    int top = n / 2;
    for (int ii=2; ii < top; ii++) {
        if(n % ii == 0) {
            int other = n / ii;
            sum_divisors += ii;
            if(other != ii)
                sum_divisors += other;
            top = other;
            if(sum_divisors > n)
                return true;
        }
    }
    return false;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unordered_set<int> abundant;
    for (int ii = 2; ii < 28124; ii++)
        if(is_abundant(ii))
            abundant.insert(ii);
   
    vector<bool> sum_abundant(28124, false); 
    for(unordered_set<int>::iterator ii = abundant.begin(); ii != abundant.end(); ii++) {
        for(unordered_set<int>::iterator jj = abundant.begin(); jj != abundant.end(); jj++) { 
            int sum = (*ii) + (*jj);
            if (sum < 28124)
                sum_abundant[sum] = true;
        }
    }
    
    unsigned long long sum = 0;
    for (unsigned int ii = 1; ii < sum_abundant.size(); ii++)
        if(!sum_abundant[ii])
            sum += ii;
    cout << "Sum: " << sum << endl;
        
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
