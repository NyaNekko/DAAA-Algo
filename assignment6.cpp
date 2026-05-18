#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
    int id;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Simple Union-Find Data Structure
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false;
        
        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
        
        return true;
    }
};

int getValidInput(const string& prompt, int minVal, int maxVal) {
    int value;
    
    while (true) {
        cout << prompt;
        
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid integer.\n";
            continue;
        }
        
        cin.ignore(10000, '\n');
        
        if (value < minVal || value > maxVal) {
            cout << "Error: Value must be between " << minVal << " and " << maxVal << ".\n";
            continue;
        }
        
        return value;
    }
}

// Kruskal's Algorithm
void kruskalMST(vector<Edge>& edges, int vertices) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    UnionFind uf(vertices);
    vector<Edge> mstEdges;
    int totalCost = 0;
    
    cout << "Edges sorted by weight:\n";
    cout << "-----------------------------------\n";
    for (auto& e : edges) {
        cout << "Edge " << e.id << ": (" << e.u << " ─ " << e.v << ") Weight: " << e.weight << "\n";
    }
    
    cout << "\n\nBuilding MST:\n";
    cout << "-----------------------------------\n";
    
    int stepCount = 0;
    for (auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            stepCount++;
            mstEdges.push_back(edge);
            
            cout << "Step " << stepCount << ": Added Edge " << edge.id 
                 << " (" << edge.u << " ─ " << edge.v << ") "
                 << "Weight: " << edge.weight << "\n";
            
            totalCost += edge.weight;
            
            if (mstEdges.size() == vertices - 1) break;
        } else {
            cout << "  ✗ Skipped Edge " << edge.id << " (would create cycle)\n";
        }
    }
    
    cout << "-----------------------------------\n\n";
    
    if (mstEdges.size() == vertices - 1) {
        cout << "MST Successfully Built!\n";
        cout << "Total Weight of MST: " << totalCost << "\n";
        cout << "Number of Edges: " << mstEdges.size() << "\n\n";
        
        cout << "MST Edges:\n";
        for (auto& e : mstEdges) {
            cout << "  Edge " << e.id << ": (" << e.u << " ─ " << e.v << ") Weight: " << e.weight << "\n";
        }
    } else {
        cout << " Graph is disconnected! Cannot form complete MST.\n";
    }
}

int main() {
    int vertices = getValidInput("\nEnter number of vertices (2-100): ", 2, 100);
    
    vector<Edge> edges;
    set<pair<int, int>> existingEdges;
    
    int maxEdges = (vertices * (vertices - 1)) / 2;
    int numEdges = getValidInput("Enter number of edges (1-" + to_string(maxEdges) + "): ", 1, maxEdges);
    
    cout << "\nEnter edges (undirected graph):\n";
    cout << "Format: vertex1 vertex2 weight\n";
    cout << "-----------------------------------\n";
    
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        
        while (true) {
            cout << "\nEdge " << (i + 1) << ":\n";
            u = getValidInput("  From vertex (0-" + to_string(vertices - 1) + "): ", 0, vertices - 1);
            v = getValidInput("  To vertex (0-" + to_string(vertices - 1) + "): ", 0, vertices - 1);
            weight = getValidInput("  Weight (1-1000): ", 1, 1000);
            
            if (u == v) {
                cout << "Error: Self-loops not allowed.\n";
                continue;
            }
            
            int a = min(u, v);
            int b = max(u, v);
            
            if (existingEdges.count({a, b})) {
                cout << "Error: Duplicate edge detected.\n";
                continue;
            }
            
            break;
        }
        existingEdges.insert({min(u, v), max(u, v)});
        edges.push_back({u, v, weight, (i + 1)});
        cout << "Edge added!\n";
    }
    kruskalMST(edges, vertices);
    
    cout << "\n";
    return 0;
}