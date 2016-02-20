// The fraction 49/98 is a curious fraction, as an inexperienced 
// mathematician in attempting to simplify it may incorrectly believe 
// that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
// 
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
// 
// There are exactly four non-trivial examples of this type of fraction, 
// less than one in value, and containing two digits in the numerator 
// and denominator.
// 
// If the product of these four fractions is given in its lowest common 
// terms, find the value of the denominator.

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int prod_num = 1;
    int prod_den = 1;
    for (int num = 11; num < 99; num++) {
        if (num % 10 == 0 || num % 11 == 0) 
            continue;
        for (int den = num + 1; den < 99; den++) {
            if (den % 10 == 0 || den % 11 == 0)
                continue;
            if( num % 10 != den / 10)
                continue;

            double orig = (double)num / den;
            double alt = (double)(num/10) / (den%10);

            if(orig == alt) {
                prod_num *= num;
                prod_den *= den;
                cout << num << " / " << den << endl;
            }
        }
    }
    int d = gcd(prod_num, prod_den);
    while(d > 1) {
        prod_num /= d;
        prod_den /= d;
        d = gcd(prod_num, prod_den);
    }
    cout << prod_num << " / " << prod_den << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
