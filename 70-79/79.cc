// A common security method used for online banking is to ask the user for three random 
// characters from a passcode. For example, if the passcode was 531278, they may ask for 
// the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
// 
// The text file, keylog.txt, contains fifty successful login attempts.
// 
// Given that the three characters are always asked for in order, analyse the file so as to 
// determine the shortest possible secret passcode of unknown length.

// Initially solved with a pen and paper in about 30 seconds
// Made solution afterwards
// Solution doesn't deal with repeated characters :-(

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef struct {
    char left;
    char right;
} rule;

bool check_rule(string pw, rule r) {
    if(pw.find(r.left) < pw.rfind(r.right))
        return true;
    return false;
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    //construct rules from file
    vector<rule> rules;
    set<char> digits;
    ifstream f ("79.txt");
    string line;
    if(f.is_open()) {
        for (unsigned int att = 0; att < 50; att++) {
            getline(f, line);
            digits.insert(line[0]);
            digits.insert(line[1]);
            digits.insert(line[2]);
            rule one, two;
            one.left = line[0];
            one.right = line[1];
            two.left = line[1];
            two.right = line[2];
            rules.push_back(one);
            rules.push_back(two);
        }
        f.close();
    } else { 
        cout << "Couldn't open 79.txt" << endl;
        return 1;
    }

    //create initial password
    string pw = "";
    for(set<char>::iterator it = digits.begin(); it != digits.end(); it++)
        pw += *it;
    
    //iterate through permutations, exit on one that meets all the rules
    bool found = false;
    do {
        found = true; 
        for(unsigned int ii = 0; ii < rules.size(); ii++) {
            if(!check_rule(pw, rules[ii])) {
                found = false;
                next_permutation(pw.begin(), pw.end());
                break;
            }
        }
    } while (!found);

    cout << pw << endl;
    
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
