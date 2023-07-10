// topological sort using BFS

#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


vector<int> toposort(int v, vector<int> adj[]){
    int indgr[v]={0};
    for(int i=0;i<v;i++)
    {
        for (auto it:adj[i])
        {
            indgr[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indgr[i]) q.push(i);
    }
    vector<int> topsrt;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topsrt.push_back(node);

        for(auto it:adj[node])
        {
            indgr[it]--;
            if (!indgr[it])  q.push(it);

        }
    }

    return topsrt;

} 