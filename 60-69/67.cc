// By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
// the maximum total from top to bottom is 23.
// 
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// 
// That is, 3 + 7 + 4 + 9 = 23.
// 
// Find the maximum total from top to bottom in triangle.txt (right click and 
// 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
// 
// NOTE: This is a much more difficult version of Problem 18. It is not possible to try 
// every route to solve this problem, as there are 299 altogether! If you could check one 
// trillion (10^12) routes every second it would take over twenty billion years to check them 
// all. There is an efficient algorithm to solve it. ;o)

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int pyramid[100][100];
    ifstream f ("67.txt");
    string line;
    if(f.is_open()) {
        for (unsigned int row = 0; row < 100; row++) {
            getline(f, line);
            istringstream iss(line);
            for(unsigned int col = 0; col <= row; col++)
                iss >> pyramid[row][col];
        }
        f.close();
    }
    for(int row = 98; row >= 0; row--) {
        for(int col = 0; col <= row; col++) {
        if(pyramid[row + 1][col] > pyramid[row + 1][col + 1])
            pyramid[row][col] += pyramid[row + 1][col];
        else
            pyramid[row][col] += pyramid[row + 1][col + 1];
        }
    }
    cout << pyramid[0][0] << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
