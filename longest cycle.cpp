#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestCycle(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> graph(n);
        
        // Build the graph as an adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]); // Since it's an undirected graph
        }

        int maxCycleLength = 0;
        vector<bool> visited(n, false);
        
        // Perform DFS to find cycles
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_map<int, int> parent;
                maxCycleLength = max(maxCycleLength, dfs(i, -1, visited, parent, graph));
            }
        }
        
        return maxCycleLength;
    }

private:
    int dfs(int node, int par, vector<bool>& visited, unordered_map<int, int>& parent, vector<unordered_set<int>>& graph) {
        visited[node] = true;
        parent[node] = par;
        
        int cycleLength = 0;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                cycleLength = max(cycleLength, dfs(neighbor, node, visited, parent, graph));
            } else if (neighbor != par) { // A cycle is found
                // Calculate cycle length
                cycleLength = max(cycleLength, getCycleLength(node, neighbor, parent));
            }
        }
        
        return cycleLength;
    }

    int getCycleLength(int startNode, int endNode, unordered_map<int, int>& parent) {
        int length = 0;
        
        // Traverse from startNode to endNode to calculate the cycle length
        for (int node = startNode; node != endNode; node = parent[node]) {
            length++;
        }
        
        // Include the endNode in the cycle count
        return length + 1; 
    }
};

int main() {
    Solution solution;

    // Example graph represented as edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 3}}; // Contains a cycle: 0 -> 1 -> 2 -> 0 and 3 -> 4 -> 5 -> 3

    int longestCycleLength = solution.longestCycle(edges);
    cout << "The length of the longest cycle in the graph is: " << longestCycleLength << endl;

    return 0;
}