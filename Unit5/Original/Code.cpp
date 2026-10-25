#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Maze {
    int V;
    vector<vector<int>> adj;

public:
    Maze(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add a passage between two junctions
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform BFS from entrance to check exit
    void BFS(int start, int exit) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nJunctions visited in BFS order: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        if (visited[exit]) {
            cout << "\nPath exists from entrance "
                 << start << " to exit " << exit << ".";
        } else {
            cout << "\nNo path exists from entrance "
                 << start << " to exit " << exit << ".";
        }

        cout << endl;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of junctions: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Invalid number of junctions." << endl;
        return 0;
    }

    Maze maze(vertices);

    cout << "Enter number of passages: ";
    cin >> edges;

    if (edges < 0) {
        cout << "Invalid number of passages." << endl;
        return 0;
    }

    cout << "Enter passages (junction1 junction2):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices) {
            cout << "Invalid junction number." << endl;
            return 0;
        }

        maze.addEdge(u, v);
    }

    int entrance, exit;

    cout << "Enter entrance junction: ";
    cin >> entrance;

    cout << "Enter exit junction: ";
    cin >> exit;

    if (entrance < 0 || entrance >= vertices ||
        exit < 0 || exit >= vertices) {
        cout << "Invalid entrance or exit junction." << endl;
        return 0;
    }

    maze.BFS(entrance, exit);

    return 0;
}
