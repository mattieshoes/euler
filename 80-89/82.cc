// NOTE: This problem is a significantly more challenging version of Problem 81.
// 
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, 
// by moving left, right, up, and down, is indicated in bold red and is equal to 2297.
// 
// Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), 
// a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right 
// by moving left, right, up, and down.

// Solve right to left, don't backtrack (no going up-down-up-down)

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <climits>

#define DIM 80

using namespace std;

int search(int matrix[][DIM], int solved[][DIM], int row, int col, int current, int best, int skip) {
    //cutoff if we can't improve best
    if(current >= best)
        return best;
    int score;
    //search right
    if(col < DIM-1) {
        if (solved[row][col+1] > 0)
            score = current + solved[row][col+1];
        else 
            score = search(matrix, solved, row, col+1, current + matrix[row][col+1], best, 0);
        if(score < best)
            best = score;
    }
    //search down
    if(row < DIM-1 && skip != 1) {
        if (solved[row+1][col] > 0)
            score = current + solved[row+1][col];
        else 
            score = search(matrix, solved, row+1, col, current + matrix[row+1][col], best, 2);
        if(score < best)
            best = score;
    }
    //search up
    if(row > 0 && skip != 2) {
        if (solved[row-1][col] > 0)
            score = current + solved[row-1][col];
        else 
            score = search(matrix, solved, row-1, col, current + matrix[row-1][col], best, 1);
        if(score < best)
            best = score;
    }
    return best;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    //construct matrix from file
    int matrix[DIM][DIM];
    int solved[DIM][DIM];
    ifstream f ("82.txt");
    string line, field;
    if (f.is_open()) {
        for (unsigned int row = 0; row < DIM; row++) {
            getline(f, line);
            istringstream iss (line);
            for (unsigned int col = 0; col < DIM; col++) {
                getline(iss, field, ',');
                matrix[row][col] = stoi(field);
                solved[row][col] = 0;
            }
        }
        f.close();
    } else { 
        cout << "Couldn't open 82.txt" << endl;
        return 1;
    }

    //end spots are solved by definition
    for (int ii = 0; ii < DIM; ii++)
        solved[ii][DIM-1] = matrix[ii][DIM-1];

    //solve right-to-left to minimize tree search
    for (int col = DIM-2; col >= 0; col--)
        for (int row = 0; row < DIM; row++)
            solved[row][col] = search(matrix, solved, row, col, matrix[row][col], INT_MAX, 0);
    
    // find cheapest starting spot
    int min = INT_MAX;
    for (int row = 0; row < DIM; row++)
        if (solved[row][0] < min)
            min = solved[row][0];

    cout << min << endl;


    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
