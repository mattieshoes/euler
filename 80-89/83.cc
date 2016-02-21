// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by 
// moving left, right, up, and down, is indicated in bold red and is equal to 2297.
// 
// Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), 
// a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right 
// by moving left, right, up, and down.
// 
// Implementation Dijkstra's algorithm to solve shortest path to all nodes

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <climits>

#define DIM 80
#define ROW(x) ((x)/DIM)
#define COL(x) ((x)%DIM)

using namespace std;

class Node{
  public:
    Node(int Cost);
    int cost;
    int total_cost;
};
Node::Node(int Cost) {
    cost = Cost;
    total_cost = INT_MAX;
}

void visit_cheapest(vector<Node> &matrix, set<int> &visited, set<int> &fringe) {
    //find cheapest from fringe
    int cheapest = INT_MAX;
    int cheapest_index = 0;
    for (set<int>::iterator it= fringe.begin(); it != fringe.end(); it++) {
       if (matrix[*it].total_cost < cheapest) {
            cheapest = matrix[*it].total_cost;
            cheapest_index = *it;
        } 
    }
    
    //move from fringe to visited
    visited.insert(cheapest_index);
    fringe.erase(cheapest_index);

    //update fringe nodes
    vector<int> to_update;
    if (ROW(cheapest_index) > 0 && visited.count(cheapest_index-DIM) == 0)
        to_update.push_back(cheapest_index-DIM);
    if (ROW(cheapest_index) < DIM-1 && visited.count(cheapest_index+DIM) == 0)
        to_update.push_back(cheapest_index+DIM);
    if (COL(cheapest_index) > 0 && visited.count(cheapest_index-1) == 0)
        to_update.push_back(cheapest_index-1);
    if (COL(cheapest_index) < DIM-1 && visited.count(cheapest_index+1) == 0)
        to_update.push_back(cheapest_index+1);

    for (unsigned int ii = 0; ii < to_update.size(); ii++) {
        fringe.insert(to_update[ii]);
        int c = matrix[cheapest_index].total_cost + matrix[to_update[ii]].cost;
        if(c < matrix[to_update[ii]].total_cost)
            matrix[to_update[ii]].total_cost = c;
    }
}

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    //construct matrix from file
    vector<Node> matrix;
    vector<int> heuristic_cost;
    ifstream f ("83.txt");
    string line, field;
    if (f.is_open()) {
        for (unsigned int row = 0; row < DIM; row++) {
            getline(f, line);
            istringstream iss (line);
            for (unsigned int col = 0; col < DIM; col++) {
                getline(iss, field, ',');
                matrix.push_back(Node(stoi(field)));
            }
        }
        f.close();
    } else { 
        cout << "Couldn't open 83.txt" << endl;
        return 1;
    }
    
    set<int> visited;
    set<int> fringe;
    matrix[0].total_cost = matrix[0].cost;
    fringe.insert(0);

    while(fringe.size() > 0)
        visit_cheapest(matrix, visited, fringe);

    cout << matrix[DIM*DIM-1].total_cost << endl;        

    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
