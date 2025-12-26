#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(dist[u] + 1 <= dist[v]){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        vector<int> res(V, -1);
        for(int i=0; i<V; i++){
            if(dist[i] != INT_MAX) res[i] = dist[i];
        }
        return res;
    }
};
