#include <bits/stdc++.h>
using namespace std;

// Method 1: Using DFS
class Solution {
  public:
    bool DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRec){
        visited[u] = true;
        inRec[u] = true;
        for(auto v : adj[u]){
            if(!visited[v] && DFS(v, adj, visited, inRec)) return true;
            else if(visited[v] && inRec[v]) return true;
        }
        inRec[u] = false; // * 
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V, false);
        vector<bool> inRec(V, false);
        for(int v=0; v<V; v++){
            if(!visited[v] && DFS(v, adj, visited, inRec)) return true;
        }
        return false;
    }
};