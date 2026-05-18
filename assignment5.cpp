#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
#include <sstream>

using namespace std;

const int INF = INT_MAX;
const int MAX_VERTICES = 100;

// Input validation function
int getValidInput(int minVal, int maxVal, const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
            continue;
        }
        
        if (value < minVal || value > maxVal) {
            cout << "Please enter a number between " << minVal << " and " << maxVal << ".\n";
            continue;
        }
        
        cin.ignore(10000, '\n');
        return value;
    }
}

// Prim's Algorithm using Adjacency Matrix
void primsMST(int adjMatrix[][MAX_VERTICES], int vertices) {
    vector<bool> inMST(vertices, false);
    vector<int> key(vertices, INF);
    vector<int> parent(vertices, -1);
    
    // Start from vertex 0
    key[0] = 0;
    int totalCost = 0;
    
    cout << "Building Minimum Spanning Tree:\n";
    
    for (int count = 0; count < vertices; count++) {
        // Find minimum key vertex not in MST
        int minKey = INF;
        int u = -1;
        
        for (int v = 0; v < vertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        
        inMST[u] = true;
        
        // Print edge (except for first vertex)
        if (parent[u] != -1) {
            cout << "Step " << count << ": Edge (" << parent[u] << " ─ " << u 
                 << ") | Weight: " << key[u] << "\n";
            totalCost += key[u];
        } else {
            cout << "Step " << count << ": Starting vertex: " << u << "\n";
        }
        
        // Update keys of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    
    cout << "Total Weight of MST: " << totalCost << "\n";
    cout << "\nEdge List of MST:\n";
    for (int i = 1; i < vertices; i++) {
        cout << "  (" << parent[i] << " ─ " << i << ")\n";
    }
}

int main() {
    int vertices = getValidInput(2, MAX_VERTICES, "\nEnter number of vertices (2-100): ");
    
    // Initialize adjacency matrix with 0 (no edge)
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    int maxEdges = (vertices * (vertices - 1)) / 2;
    int numEdges = getValidInput(1, maxEdges, 
                                 "Enter number of edges (1-" + to_string(maxEdges) + "): ");
    
    cout << "\nEnter edges (undirected graph):\n";
    cout << "Format: vertex1 vertex2 weight\n";
    
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        
        while (true) {
            cout << "\nEdge " << (i + 1) << ":\n";
            u = getValidInput(0, vertices - 1, "  From vertex (0-" + to_string(vertices - 1) + "): ");
            v = getValidInput(0, vertices - 1, "  To vertex (0-" + to_string(vertices - 1) + "): ");
            weight = getValidInput(1, 1000, "  Weight (1-1000): ");
            
            // Validation checks
            if (u == v) {
                cout << "Self-loop not allowed! Vertices must be different.\n";
                continue;
            }
            
            if (adjMatrix[u][v] != 0) {
                cout << "Edge already exists! Please enter a different edge.\n";
                continue;
            }
            
            break;
        }
        
        // Add edge to matrix (undirected graph)
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        
        cout << "Edge added successfully!\n";
    }
    
    // Run Prim's algorithm
    primsMST(adjMatrix, vertices);
    
    cout << "\n";
    return 0;
}
