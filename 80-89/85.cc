// By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains 
// eighteen rectangles:
// 
// Although there exists no rectangular grid that contains exactly two million rectangles, 
// find the area of the grid with the nearest solution.

#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

int rectangle_count(int width, int height) {
    int count = 0;
    for (int w = 1; w <= width; w++) {
        for (int h = 1; h <= height; h++) {
            count += (width-w+1) * (height-h+1);
        }
    }
    return count;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    int best_score = 2000000;
    for(int width = 1; width <= 2000; width++) {
        for(int height = 1; height <= width; height++) {
            int val = rectangle_count(width, height);
            if(abs(val-2000000) < best_score) {
                best_score = abs(val - 2000000);
                cout << width << " x " << height << " = " << val 
                     << ", Area: " << width * height << endl;
            }
            if(val > 2000000) {
                break;
            }
        }
    }

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
