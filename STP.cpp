#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int source, int n,
              vector<vector<int>>& cost,
              vector<int>& d,
              vector<int>& parent) {

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        d[i] = INF;
        parent[i] = -1;
    }

    d[source] = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;

        // Find node with minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }

        if (u == -1 || d[u] == INF)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {

            if (!visited[v] && cost[u][v] != INF) {

                // Relaxation formula
                // d[u] + c[u][v] < d[v]

                if (d[u] + cost[u][v] < d[v]) {

                    d[v] = d[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void printPath(int v, vector<int>& parent) {

    if (parent[v] == -1) {
        cout << v + 1;
        return;
    }

    printPath(parent[v], parent);
    cout << " -> " << v + 1;
}

int main() {

    int n, edges;

    cout << "Enter number of nodes (minimum 7): ";
    cin >> n;

    if (n < 7) {
        cout << "Minimum 7 nodes required!";
        return 0;
    }

    vector<vector<int>> cost(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter source destination cost:\n";

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 1 || u > n || v < 1 || v > n || w < 0) {
            cout << "Invalid edge!";
            return 0;
        }

        u--;
        v--;

        if (w < cost[u][v]) {
            cost[u][v] = w;
            cost[v][u] = w;
        }
    }

    // Fixed source node = 1
    int source = 0;

    vector<int> d(n), parent(n);

    dijkstra(source, n, cost, d, parent);

    cout << "\n========== ROUTING TABLE ==========\n";

    cout << left << setw(12) << "Source"
         << setw(15) << "Destination"
         << setw(15) << "Shortest Path" << endl;

    cout << "------------------------------------------\n";

    for (int dest = 0; dest < n; dest++) {

        if (dest == source)
            continue;

        cout << left << setw(12) << source + 1
             << setw(15) << dest + 1;

        if (d[dest] == INF)
            cout << "No Path";
        else
            cout << d[dest];

        cout << endl;
    }

    int dest;

    cout << "\nEnter destination node: ";
    cin >> dest;

    if (dest < 1 || dest > n) {
        cout << "Invalid destination!";
        return 0;
    }

    dest--;

    cout << "\n========== SHORTEST PATH ==========\n";

    if (d[dest] == INF) {
        cout << "No path exists!";
    }
    else {
        cout << "Source: 1" << endl;
        cout << "Destination: " << dest + 1 << endl;

        cout << "Shortest Path: ";
        printPath(dest, parent);

        cout << "\nTotal Cost: " << d[dest] << endl;
    }

    return 0;
}