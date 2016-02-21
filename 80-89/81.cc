// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, 
// by only moving to the right and down, is indicated in bold red and is equal to 2427.
// 
// <snip>
// 
// Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), 
// a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right 
// by only moving right and down.

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    //construct matrix from file
    int matrix[80][80];
    ifstream f ("81.txt");
    string line, field;
    if (f.is_open()) {
        for (unsigned int row = 0; row < 80; row++) {
            getline(f, line);
            istringstream iss (line);
            for (unsigned int col = 0; col < 80; col++) {
                getline(iss, field, ',');
                matrix[row][col] = stoi(field);
            }
        }
        f.close();
    } else { 
        cout << "Couldn't open 81.txt" << endl;
        return 1;
    }

    //solve for bottom and right edge (only one direction)
    for (int n = 78; n >= 0; n--) {
        matrix[79][n] += matrix[79][n+1];
        matrix[n][79] += matrix[n+1][79];
    }
    //now we basically have a 79x79 matrix, then 78x78, and so on.
    for (int rc = 78; rc >= 0; rc--) {
        if (matrix[rc][rc+1] < matrix[rc+1][rc])
            matrix[rc][rc] += matrix[rc][rc+1];
        else
            matrix[rc][rc] += matrix[rc+1][rc];
        for (int n = rc - 1; n >= 0; n--) {
            if(matrix[n][rc+1] < matrix[n+1][rc])
                matrix[n][rc] += matrix[n][rc+1];
            else
                matrix[n][rc] += matrix[n+1][rc];
            if(matrix[rc][n+1] < matrix[rc+1][n])
                matrix[rc][n] += matrix[rc][n+1];
            else
                matrix[rc][n] += matrix[rc+1][n];
        }
    }
    cout << matrix[0][0] << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
