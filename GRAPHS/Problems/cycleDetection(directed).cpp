#include <bits/stdc++.h>
using namespace std;

// Using DFS to detect cycle in a directed graph
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    bool DFS(vector<vector<int>>& edges, int u,vector<bool>& vis, vector<bool>& inRec) {
        vis[u] = true;
        inRec[u] = true;
        for (int v : edges[u]) {
            if (!vis[v]) {
                if (DFS(edges, v, vis, inRec))
                    return true;
            } else if (inRec[v]) {
                return true;
            }
        }
        inRec[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V, false);
        vector<bool> inRec(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (DFS(edges, i, vis, inRec))
                    return true;
            }
        }
        return false;
    }
};

// Using BFS 
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> indeg(V, 0);
        for(int u=0; u<V; u++){
            for(auto v : adj[u]){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0) q.push(i);
        }
        int ctr = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ctr++;
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(ctr == V) return false;
        return true;
    }
};