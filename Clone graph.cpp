#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Handle empty graph

        // Map to keep track of cloned nodes
        unordered_map<Node*, Node*> clonedNodes;

        // Start DFS from the original node
        return dfs(node, clonedNodes);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clonedNodes) {
        // If the node is already cloned, return the cloned node
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        }

        // Clone the node
        Node* cloneNode = new Node(node->val);
        clonedNodes[node] = cloneNode;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, clonedNodes));
        }

        return cloneNode;
    }
};

// Helper function to print the graph (for testing)
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;

    visited[node] = true;
    cout << "Node " << node->val << ": ";
    
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    
    cout << endl;

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Create a sample graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    // Clone the graph
    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print original and cloned graphs
    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> visited;
    printGraph(node1, visited);

    cout << "\nCloned Graph:" << endl;
    visited.clear();
    printGraph(clonedGraph, visited);

    return 0;
}