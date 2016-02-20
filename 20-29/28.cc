// Starting with the number 1 and moving to the right in a clockwise direction a 
// 5 by 5 spiral is formed as follows:
// 
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
// 
// It can be verified that the sum of the numbers on the diagonals is 101.
// 
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral 
// formed in the same way?

// 1 3 5 7 9 13 17 21 25 31 37 43 49
//  2 2 2 2 4  4  4  4  6  6  6  6  8
// last element will be 1001 x 1001 = 1002001
 
#include <iostream>
#include <chrono>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int n = 1;
    int sum = 1;
    int cycle = 0;
    int jumpsize = 2;

    while(n < 1001 * 1001) {
        n += jumpsize;
        sum += n;
        cycle++;
        if(cycle == 4) {
            cycle = 0;
            jumpsize += 2;
        }
    }
    cout << "Sum: " << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
