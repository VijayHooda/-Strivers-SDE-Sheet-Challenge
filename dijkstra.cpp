// using priority queue (min heap) vector<pair<int,int> >, 

#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V,vector<vector<int>> adjlist[],int S){
    vector<int> dist(V,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
    dist[S]=0;
    pq.push({0,S});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adjlist[node])
        {
            int edjwht = it[1];
            int adjnode = it[0];

            if (dist+edjwht < dist[adjnode]){
                dist[adjnode] = dist + edjwht;
                pq.push({dist[adjnode],adjnode});

            }
        }
    }

    return dist;
    

}