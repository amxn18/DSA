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
// Method 2: Using BFS (Kahn's Algorithm)
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> inDeg(V, 0);
        for(int u=0; u<V; u++){
            for(auto v: adj[u]) inDeg[v]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        int ctr = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ctr++;
            for(auto &v: adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }
        if(ctr == V) return false;
        return true;
    }
};