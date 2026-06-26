#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0]; 
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int u=0; u<V; u++){
            for(auto v: adj[u]){
                if(u < v){
                    int parentU = find(u);
                    int parentV = find(v);
                    if(parentU == parentV) return true;
                    Union(u, v);
                }
            }
        }
        return false;
    }
};

