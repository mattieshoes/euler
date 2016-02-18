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
