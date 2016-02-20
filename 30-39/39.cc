// If p is the perimeter of a right angle triangle with integral length 
// sides, {a,b,c}, there are exactly three solutions for p = 120.
// 
// {20,48,52}, {24,45,51}, {30,40,50}
// 
// For which value of p ≤ 1000, is the number of solutions maximised?



#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<int> sq;
    for (int ii = 0; ii <= 500; ii++)
        sq.push_back(ii*ii);

    int solutions[1001];
    for (int ii=0; ii<1001; ii++)
        solutions[ii] = 0;
    for (int ai = 1; ai <= 500; ai++){
        for (int bi=ai; bi <= 500; bi++) {
            for (int ci = bi + 1; ci <= 500; ci++) {
                if (ai + bi + ci > 1000)
                    break;
                if (sq[ci] > sq[ai] + sq[bi])
                    break;
                if(sq[ai] + sq[bi] == sq[ci]) {
                    cout << "{" << ai << "," << bi << "," << ci << "}" 
                         << " = " << ai + bi + ci << endl;
                    solutions[ai + bi + ci]++;
                }
            }
        }
    }
    int max = 0;
    for (int ii = 0; ii < 1001; ii++)
        if (solutions[ii] > solutions[max])
            max = ii;
    cout << "Perimeter with max solutions: " << max << "(" 
         << solutions[max] << ")" << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
