#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initialize each set as a separate subset with itself as the parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    // Find the root of the given vertex
    int find(int v) {
        if (parent[v] != v)
            parent[v] = find(parent[v]);
        return parent[v];
    }
    
    // Union two subsets based on rank
    void unionSets(int v1, int v2) {
        int root1 = find(v1);
        int root2 = find(v2);
        
        if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};

// Function to compare edges based on their weights in ascending order
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    // Sort the edges in ascending order based on their weights
    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<Edge> minimumSpanningTree;
    DisjointSet disjointSet(numVertices);
    
    for (const auto& edge : edges) {
        int sourceRoot = disjointSet.find(edge.source);
        int destRoot = disjointSet.find(edge.destination);
        
        // Check if including the edge creates a cycle in the MST
        if (sourceRoot != destRoot) {
            minimumSpanningTree.push_back(edge);
            disjointSet.unionSets(sourceRoot, destRoot);
        }
    }
    
    return minimumSpanningTree;
}

// Utility function to print the edges of the minimum spanning tree
void printMST(const vector<Edge>& mst) {
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto& edge : mst)
        cout << edge.source << " -- " << edge.destination << " (Weight: " << edge.weight << ")" << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    
    vector<Edge> edges(numEdges);
    cout << "Enter the details of each edge (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }
    
    vector<Edge> minimumSpanningTree = kruskalMST(edges, numVertices);
    printMST(minimumSpanningTree);
    
    return 0;
}