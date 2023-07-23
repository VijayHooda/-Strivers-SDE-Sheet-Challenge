#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<pair<pair<int, int>, int>> mst;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // as it's an undirected graph
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> vis(n+1, false);
    pq.push({0, {0, 1}});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second.second;
        int parent = it.second.first;
        int weight = it.first;
        if (!vis[node]){
            vis[node] = true;
            if (parent != 0) { // we don't want to include the edge with parent 0
                mst.push_back({{parent, node}, weight});
            }
            for(auto it: adj[node]){
                int next_node = it.first;
                int next_weight = it.second;
                if (!vis[next_node]){
                    pq.push({next_weight, {node, next_node}});
                } 
            }
        }
    }
    return mst;
}
