// In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
//
// (11.txt)
//
// The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
//
// What is the greatest product of four adjacent numbers in the same direction (up, down, left, 
// right, or diagonally) in the 20×20 grid? 

#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int grid[20][20];

    ifstream gridfile ("11.txt");
    if (gridfile.is_open()) {
        string line;
        for (int row = 0; row < 20; row++) {
            getline(gridfile, line);
            stringstream ss(line);
            for (int col = 0; col < 20; col++)
                ss >> grid[row][col];
        } 
        gridfile.close();
    }

    unsigned long long max = 0, product = 0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            if (col < 17) {
                product = grid[row][col] * grid[row][col+1] * grid[row][col+2] * grid[row][col+3];
                if (product > max)
                    max = product;
            }
            if (row < 17) {
                product = grid[row][col] * grid[row+1][col] * grid[row+2][col] * grid[row+3][col];
                if (product > max)
                    max = product;
            }
            if (row < 17 && col < 17) {
                product =   grid[row][col] * grid[row+1][col+1] * grid[row+2][col+2] * 
                            grid[row+3][col+3];
                if (product > max)
                    max = product;
            }
            if (row < 17 && col > 2) {
                product =   grid[row][col] * grid[row+1][col-1] * grid[row+2][col-2] * 
                            grid[row+3][col-3];
                if (product > max)
                    max = product;
            }
        }
    }
    
    cout << "Max product: " << max << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
