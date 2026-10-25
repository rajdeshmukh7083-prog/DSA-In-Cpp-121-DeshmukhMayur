#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform BFS from a user-defined starting vertex
    void BFS(int start) {
        vector<bool> visited(V, false);
        vector<int> level(V, -1);
        queue<int> q;

        visited[start] = true;
        level[start] = 0;
        q.push(start);

        cout << "\nBFS Traversal Order: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    level[neighbor] = level[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        cout << "\n\nReachable Vertices: ";
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                cout << i << " ";
                count++;
            }
        }

        cout << "\nUnvisited Vertices: ";
        bool found = false;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << "\nTotal Reachable Vertices: "
             << count;

        cout << "\n\nBFS Levels:\n";

        for (int i = 0; i < V; i++) {
            if (visited[i])
                cout << "Vertex " << i
                     << " : Level " << level[i] << endl;
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges < 0) {
        cout << "Invalid number of edges.\n";
        return 0;
    }

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices) {
            cout << "Invalid vertex number.\n";
            return 0;
        }

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return 0;
    }

    g.BFS(start);

    return 0;
}
