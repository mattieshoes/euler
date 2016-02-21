// Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
// 
// Triangle        Tn=n(n+1)/2     1, 3, 6, 10, 15, ...
// Pentagonal      Pn=n(3n−1)/2        1, 5, 12, 22, 35, ...
// Hexagonal       Hn=n(2n−1)      1, 6, 15, 28, 45, ...
// It can be verified that T285 = P165 = H143 = 40755.

#include <iostream>
#include <chrono>

using namespace std;

unsigned long long triangle(unsigned long long n) {
    return n * (n+1) / 2;
}
unsigned long long pentagonal(unsigned long long n) {
    return n * (3*n-1) / 2;
}

unsigned long long hexagonal(unsigned long long n) {
    return n * (2 * n - 1);
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    unsigned long long tri_index = 286;
    unsigned long long pent_index = 166;
    unsigned long long hex_index = 144;

    unsigned long long tri = triangle(tri_index);
    unsigned long long pent = pentagonal(pent_index);
    unsigned long long hex = hexagonal(hex_index);

    while ( tri != pent || tri != hex) {
        if (tri < pent && tri < hex) {
            tri_index++;
            tri = triangle(tri_index);
        } else if (pent < hex) {
            pent_index++;
            pent = pentagonal(pent_index);
        } else {
            hex_index++;
            hex = hexagonal(hex_index);
        }
    } 
    cout << "T(" << tri_index << ") = P(" << pent_index << ") = H(" << hex_index << ") = "
         << tri << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}