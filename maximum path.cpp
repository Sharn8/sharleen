#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxQuality = 0; // To store the maximum quality found

    void dfs(int currentNode, int remainingTime, int currentQuality, 
             vector<int>& values, vector<vector<pair<int, int>>>& graph, 
             vector<bool>& visited) {
        // If we return to the starting node (0), check for maximum quality
        if (currentNode == 0) {
            maxQuality = max(maxQuality, currentQuality);
        }

        // Explore all neighbors
        for (auto& neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int travelTime = neighbor.second;

            // If there's enough remaining time to traverse to the next node
            if (remainingTime >= travelTime) {
                // Mark the neighbor as visited
                bool wasVisited = visited[nextNode];
                visited[nextNode] = true;

                // Update quality if it's the first visit to this node
                int newQuality = currentQuality + (wasVisited ? 0 : values[nextNode]);

                // Recur for the next node with updated remaining time and quality
                dfs(nextNode, remainingTime - travelTime, newQuality, values, graph, visited);

                // Backtrack: unmark the neighbor after exploring
                visited[nextNode] = wasVisited;
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n);

        // Build the graph from edges
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]); // {neighbor, time}
            graph[edge[1]].emplace_back(edge[0], edge[2]); // Undirected graph
        }

        vector<bool> visited(n, false); // Track visited nodes

        // Start DFS from node 0 with initial conditions
        visited[0] = true; // Start at node 0
        dfs(0, maxTime, values[0], values, graph, visited);

        return maxQuality; // Return the maximum quality found
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> values = {0, 32, 10, 43}; // Values of nodes
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}}; // Edges with travel times
    int maxTime = 49; // Maximum allowed time

    int result = solution.maximalPathQuality(values, edges, maxTime);
    cout << "The maximum path quality is: " << result << endl; // Output should be the maximum path quality within the given maxTime

    return 0;
}