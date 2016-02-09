// In England the currency is made up of pound, £, and pence, p, and there are eight coins in 
// general circulation:
// 
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// It is possible to make £2 in the following way:
// 
// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?

// TODO: does caching partial results save time? Probably...

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

unsigned long long coin_count_combinations(int left, vector<int> options) {
    if (left == 0)
        return 1ULL;
    unsigned long long sum_combinations = 0; 
    while (options.size() > 0) {
        int val = left - options.back();
        if(val >= 0)
            sum_combinations += coin_count_combinations(val, options);
        options.pop_back(); 
    } 
    return sum_combinations;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<int> options = {1, 2, 5, 10, 20, 50, 100, 200 };
    unsigned long long combinations = coin_count_combinations(200, options);

    cout << "Combinations: " << combinations << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
