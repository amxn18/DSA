#include <bits/stdc++.h>
using namespace std;

// Connected Components in Undirected Graph
// TC : O(V+E) and SC: O(V+E) for adj list + O(V) for visited array + O(V) for recursion stack.
class Solution {
  public:
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component){
        visited[u] = true;
        component.push_back(u);
        for(auto &v: adj[u]){
            if(!visited[v]) DFS(v, adj, visited, component);
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // Edge List -> Adj List
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<vector<int>> ans;
        vector<bool> visited(V, false);
        for(int v=0; v<V; v++){
            if(!visited[v]){
                vector<int> component;
                DFS(v, adj, visited, component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};
