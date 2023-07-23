#include <bits/stdc++.h> 
using namespace  std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // as it's an undirected graph
    }

    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for(auto it:adj[i]){
            int u = i;
            int v = it.first;
            int w = it.second;
            edges.push_back({w,{u,v}});

        }
    }
    DisjointSet ds(n);
    sort(edges.begin(), edges.end());

    int minwt = 0;
    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u)!=ds.findUPar(v)){
            ds.unionBySize(u,v);
            minwt+=wt;

        }
    }
    return minwt;



}