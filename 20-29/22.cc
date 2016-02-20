// Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over 
// five-thousand first names, begin by sorting it into alphabetical order. Then working out the 
// alphabetical value for each name, multiply this value by its alphabetical position in the 
// list to obtain a name score.
// 
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 
// 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 
// 938 × 53 = 49714.
// 
// What is the total of all the name scores in the file?

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    ifstream namefile ("22.txt");
    vector<string> name;
    if(namefile.is_open()) {
        string line;
        while(getline (namefile, line, ','))
            name.push_back(line.substr(1,line.size()-2));
        namefile.close();
    }

    sort (name.begin(), name.end()); 

    unsigned long long sum = 0;   
    for (unsigned int n = 0; n < name.size(); n++) {
        int s = 0;
        for(unsigned int c = 0; c < name[n].size(); c++) {
            s += name[n][c] - 'A' + 1;
        }
        sum += s * (n + 1);
    }
    cout << "Sum: " << sum << endl;

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
