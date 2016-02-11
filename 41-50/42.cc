// We shall say that an n-digit number is pandigital if it makes use of all 
// the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital 
// and is also prime.
// 
// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int tri(int index) {
    return (index*(index+1))/2;
}
bool is_triangular(int n) {

    int ii = 1;
    int jj = tri(1);

    while(jj < n) {
        ii++;
        jj = tri(ii);
    }
    if(jj == n)
        return true;
    return false;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    for(int ii=1;ii<=26;ii++) 
        cout << ii << ": " << tri(ii) << endl;

    ifstream wordfile ("42.txt");
    vector<string> word;
    if(wordfile.is_open()) {
        string line;
        while(getline (wordfile, line, ','))
            word.push_back(line.substr(1,line.size()-2));
        wordfile.close();
    }

    unsigned int count = 0;
    for (unsigned int ii = 0; ii < word.size(); ii++) {
        int word_value = 0;
        for (unsigned int jj = 0; jj < word[ii].size(); jj++) {
            word_value += word[ii][jj] - 'A' + 1;
        }
        if(is_triangular(word_value)) {
            cout << word[ii] << ": " << word_value << endl;
            count++;
        }
    }
    cout << "Count: " << count << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
