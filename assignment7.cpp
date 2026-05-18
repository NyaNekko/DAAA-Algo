#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;

typedef pair<int, int> pii;

class Graph {
private:
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    bool addEdge(int u, int v, int w) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex! Try again.\n";
            return false;
        }
        if (w < 0) {
            cout << "Negative weights not allowed! Try again.\n";
            return false;
        }

        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i].first == v) {
                cout << "Edge between " << u << " and " << v << " already exists! Try again.\n";
                return false;
            }
        }

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        return true;
    }

    pair<vector<int>, vector<int>> dijkstra(int source) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        set<pii> st;

        dist[source] = 0;
        st.insert({0, source});

        while (!st.empty()) {
            int currentDist = st.begin()->first;
            int u = st.begin()->second;
            st.erase(st.begin());

            if (currentDist > dist[u]) continue;

            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].first;
                int weight = adj[u][j].second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    st.insert({dist[v], v});
                }
            }
        }
        return {dist, parent};
    }

    void printPath(vector<int>& parent, int vertex) {
        if (vertex == -1) return;
        printPath(parent, parent[vertex]);
        cout << vertex << " ";
    }

    void display(vector<int>& dist, vector<int>& parent, int source) {
        cout << "\nShortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Vertex " << i << " : INF (No path)\n";
            } else {
                cout << "Vertex " << i << " : " << dist[i] << " | Path: ";
                printPath(parent, i);
                cout << "\n";
            }
        }
    }
};

int main() {
    int V, E;

    while (true) {
        cout << "Enter number of vertices: ";
        cin >> V;

        if (!cin.fail() && V > 0) break;

        cout << "Invalid input! Enter a positive integer.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    Graph g(V);

    while (true) {
        cout << "Enter number of edges: ";
        cin >> E;

        if (!cin.fail() && E >= 0) break;

        cout << "Invalid input! Enter a non-negative integer.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\n--- Edge Input Section ---\n";

    for (int i = 0; i < E; ) {
        int u, v, w;

        cout << "\nEnter details for Edge " << i + 1 << ":\n";

        cout << "Vertex 1 (u): ";
        cin >> u;

        cout << "Vertex 2 (v): ";
        cin >> v;

        cout << "Weight (w): ";
        cin >> w;

        if (cin.fail()) {
            cout << "Invalid input format! Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue; // same edge repeatt
        }

        if (g.addEdge(u, v, w)) {
            i++; // move fwd if it is valid
        }
    }

    int source;

    while (true) {
        cout << "\nEnter source vertex: ";
        cin >> source;

        if (!cin.fail() && source >= 0 && source < V) break;

        cout << "Invalid source! Try again.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    pair<vector<int>, vector<int>> result = g.dijkstra(source);
    vector<int> dist = result.first;
    vector<int> parent = result.second;
    g.display(dist, parent, source);

    return 0;
}