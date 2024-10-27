#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center of the star graph will be one of the nodes in the first edge.
        // We check which node from the first edge is also present in the second edge.
        
        // Extract nodes from the first edge
        int firstNode = edges[0][0];
        int secondNode = edges[0][1];

        // Check the second edge for either of the nodes from the first edge
        if (edges[1][0] == firstNode || edges[1][1] == firstNode) {
            return firstNode; // First node is the center
        } else {
            return secondNode; // Second node is the center
        }
    }
};

int main() {
    Solution solution;
    
    // Example star graph edges
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}}; // Node 2 is the center

    int center = solution.findCenter(edges);
    cout << "The center of the star graph is: " << center << endl;

    return 0;
}