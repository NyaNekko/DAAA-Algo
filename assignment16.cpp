#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    bool addEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex! Try again.\n";
            return false;
        }
        if (u == v) {
            cout << "Self Loop, Try again.\n";
            return false;
        }
        if (adj[u][v] == 1) {
            cout << "Edge between " << u << " and " << v << " already exists Try again.\n";
            return false;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
        return true;
    }

    bool isSafe(int v, vector<int>& path, int pos) {
        // check if v is adjacent to the last added vertex
        if (adj[path[pos - 1]][v] == 0)
            return false;

        // check if v is already in the path
        for (int i = 0; i < pos; i++) {
            if (path[i] == v)
                return false;
        }
        return true;
    }

    void solve(vector<int>& path, int pos, vector<vector<int>>& allCycles) {
        // all vertices are included in the path
        if (pos == V) {
            // check if there is an edge from last vertex to first vertex
            if (adj[path[pos - 1]][path[0]] == 1) {
                allCycles.push_back(path);
            }
            return;
        }

        // try each vertex as the next candidate
        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                solve(path, pos + 1, allCycles);

                path[pos] = -1; // backtrack
            }
        }
    }

    void findHamiltonianCycle() {
        vector<int> path(V, -1);
        vector<vector<int>> allCycles;

        // start from vertex 0
        path[0] = 0;

        solve(path, 1, allCycles);

        if (allCycles.size() == 0) {
            cout << "\nNo Hamiltonian Cycle exists.\n";
        } else {
            cout << "\nTotal Hamiltonian Cycles: " << allCycles.size() << endl;
            for (int k = 0; k < allCycles.size(); k++) {
                cout << "Cycle " << k + 1 << ": ";
                for (int i = 0; i < V; i++) {
                    cout << allCycles[k][i] << " -> ";
                }
                cout << allCycles[k][0] << endl;
            }
        }
    }
};

int main() {
    int V, E;

    while (true) {
        cout << "Enter number of vertices: ";
        cin >> V;

        if (cin.fail()) {
            cout << "Invalid input! Enter a valid integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (V <= 0) {
            cout << "Invalid input! Enter a positive integer.\n";
        } else {
            break;
        }
    }

    Graph g(V);

    while (true) {
        cout << "Enter number of edges: ";
        cin >> E;

        if (cin.fail()) {
            cout << "Invalid input! Enter a valid integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (E < 0) {
            cout << "Invalid input! Enter a non-negative integer.\n";
        } else {
            break;
        }
    }

    cout << "\n--- Edge Input Section ---\n";

    for (int i = 0; i < E; ) {
        int u, v;

        cout << "\nEnter details for Edge " << i + 1 << ":\n";

        cout << "Vertex 1 (u): ";
        cin >> u;

        cout << "Vertex 2 (v): ";
        cin >> v;

        if (cin.fail()) {
            cout << "Invalid input format! Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (g.addEdge(u, v)) {
            i++;
        }
    }

    g.findHamiltonianCycle();
    
    return 0;
}
