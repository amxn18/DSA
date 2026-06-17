#include <bits/stdc++.h>
using namespace std;

// Using DFS 
// TC: O(E) {Adjcancy List} + O(V) {Each vertex} + O(E) {Inside DFS} → TC: O(V+ E)  
// SC: O(V+E) {Adjacency List} + O(V) {visited array} + O(V) {Rec Stack} -> SC : O(V+E)

class Solution {
public:
    bool dfs(int u,
             unordered_map<int, vector<int>>& adj,
             vector<bool>& visited,
             int parent) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (visited[v] && v != parent) return true;
            if (!visited [v] && dfs(v, adj, visited, u)) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int u = 0; u < V; u++) {
            for (int v : edges[u]) {
                adj[u].push_back(v);
            }
        }
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

// Using BFS 
// TC: O(V+E), SC: O(V+E)
class Solution {
  public:
    typedef pair<int, int> P;
    bool checkBFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int parent){
        queue<P> q;
        visited[u] = true;
        q.push({u, parent});
        while(!q.empty()){
            P curr = q.front();
            q.pop();
            int src = curr.first;
            int parent = curr.second;
            for(auto v : adj[src]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v,src});
                }
                else if(visited[v] == true && v != parent) return true; // cycle
            }
            return false;
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int u=0; u<V; u++){
            for(auto v : edges[u]){
                adj[u].push_back(v);
            }
        }
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && checkBFS(i, adj, visited, -1)) return true;
        }
        return false;
    }
};