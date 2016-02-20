// A permutation is an ordered arrangement of objects. For example, 3124 is one possible 
// permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically 
// or alphabetically, we call it lexicographic order. The lexicographic permutations of 
// 0, 1 and 2 are:
// 
// 012   021   102   120   201   210
// 
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>

#define MAGIC 1000000

using namespace std;

int lex(string current, int rank) {
    
    if (current.size() == 10) {
        rank++;
        if(rank == MAGIC)
            cout << current << endl;
        return rank;
    }

    //find unused 
    vector<string> left;
    for (int ii=0; ii < 10 ; ii++) {
        stringstream ss;
        ss << ii;
        string ii_s = ss.str();
        if (current.find(ii_s) == string::npos) //not in current string
            left.push_back(ii_s);
    }
    
    //add sequentially
    for (unsigned int ii = 0; ii < left.size(); ii++) {
        rank = lex(current + left[ii], rank);
        if(rank >= MAGIC)
            return rank;
    }
    return rank;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    lex("", 0);
        
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
