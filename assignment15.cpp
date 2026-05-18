#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<int> color;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
        color.resize(V, 0);
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
            cout << "Edge between " << u << " and " << v << " already exists! Try again.\n";
            return false;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
        return true;
    }

    bool isSafe(int v, int c) {
        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && color[i] == c) {
                return false;
            }
        }
        return true;
    }

    bool graphColoringUtil(int v, int m) {
        if (v == V) {
            return true;
        }

        for (int c = 1; c <= m; c++) {
            if (isSafe(v, c)) {
                color[v] = c;

                if (graphColoringUtil(v + 1, m)) {
                    return true;
                }

                color[v] = 0;
            }
        }
        return false;
    }

    void solve(int m) {
        cout << "\n--- Solving Graph Coloring ---\n";
        if (graphColoringUtil(0, m)) {
            cout << "Solution exists! Color assignment:\n";
            for (int i = 0; i < V; i++) {
                cout << "  Vertex " << i << " --> Color " << color[i] << "\n";
            }
        } else {
            cout << "No solution exists with " << m << " colors.\n";
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

    int m;

    while (true) {
        cout << "\nEnter number of colors (m): ";
        cin >> m;

        if (cin.fail()) {
            cout << "Invalid input! Enter a valid integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (m <= 0) {
            cout << "Invalid input! Enter a positive integer.\n";
        } else {
            break;
        }
    }

    g.solve(m);

    return 0;
}