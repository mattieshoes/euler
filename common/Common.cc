#include <sstream>
#include "Common.h"

bool is_decimal_permutation(unsigned long long a, unsigned long long b) {
    int d[10] = {0,0,0,0,0,0,0,0,0,0};    
    while (a > 0) {
        d[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        d[b % 10]--;
        b/=10;
    }
    if(d[0] == 0 && d[1] == 0 && d[2] == 0 && d[3] == 0 && d[4] == 0 && 
       d[5] == 0 && d[6] == 0 && d[7] == 0 && d[8] == 0 && d[9] == 0)
        return true;
    return false;
}

int decimal_digits(unsigned long long n) {
    if( n < 10ULL) return 1;
    if( n < 100ULL) return 2;
    if( n < 1000ULL) return 3;
    if( n < 10000ULL) return 4;
    if( n < 100000ULL) return 5;
    if( n < 1000000ULL) return 6;
    if( n < 10000000ULL) return 7;
    if( n < 100000000ULL) return 8;
    if( n < 1000000000ULL) return 9;
    if( n < 10000000000ULL) return 10;
    if( n < 100000000000ULL) return 11;
    if( n < 1000000000000ULL) return 12;
    if( n < 10000000000000ULL) return 13;
    if( n < 100000000000000ULL) return 14;
    if( n < 1000000000000000ULL) return 15;
    if( n < 10000000000000000ULL) return 16;
    if( n < 100000000000000000ULL) return 17;
    if( n < 1000000000000000000ULL) return 18;
    if( n < 10000000000000000000ULL) return 19;
    return 20;
}

bool is_palindrome(std::string s) {
    for(unsigned int a = 0, b = s.size()-1; a < b; a++, b--)
        if(s[a] != s[b])
            return false;
    return true;
}

cln::cl_I sum_digits(cln::cl_I val) {
    std::stringstream ss;
    ss >> val;
    std::string s = ss.str();
    cln::cl_I sum = 0;
    for (unsigned int ii = 0; ii < s.size(); ii++)
        sum += s.substr(ii, 1).c_str();
    return sum;
}
