#include <bits/stdc++.h>
using namespace std;

// LC 547. Number of Provinces
// M1: Using adj matrix -> TC: O(V^2) and SC: O(V) for recursion stack & visited array.
class Solution {
public:
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& vis, int V){
        if(vis[u] == true) return;
        vis[u] = true;
        for(int v=0; v<V; v++){
            if(adj[u][v] == 1 && !vis[v]) DFS(v, adj, vis, V);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> vis(V, false);
        int ctr = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                ctr++;
                DFS(i, isConnected, vis, V);
            }
        }
        return ctr;
    }
};

// Using adj list -> TC : O(V^2) {adj list} + O(V+E) {DFS}, SC : O (V+ E) {adj list} + O(V) {visited} + O(V) {rec stack}.
class Solution {
public:
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v]) DFS(v, adj, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i != j && isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        vector<bool> visited(V, false);
        int ctr = 0;
        for(int v=0; v<V; v++){
            if(!visited[v]){
                ctr++;
                DFS(v, adj, visited);
            }
        }
        return ctr;
    }
};