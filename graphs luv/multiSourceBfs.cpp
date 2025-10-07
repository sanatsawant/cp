// Multi-source BFS (C++)
// Inputs:
// n m          : number of nodes (1-indexed) and edges
// next m lines : edges (u v) -- undirected by default
// k            : number of sources
// next line    : k source nodes
// Output:
// distance from nearest source to every node (INF if unreachable)

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // remove if directed
    }

    int k; cin >> k;
    queue<int> q;
    vi dist(n+1, INF);
    for (int i = 0; i < k; ++i) {
        int s; cin >> s;
        if (dist[s] == INF) {
            dist[s] = 0;
            q.push(s);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
