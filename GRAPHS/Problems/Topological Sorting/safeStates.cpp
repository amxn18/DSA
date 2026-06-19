#include <bits/stdc++.h>
using namespace std;
// LC 802. Find Eventual Safe States
// DFS Cycle Detection --> O(V + E) time and O(V) space
class Solution {
public:
    bool DFS(int u, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& inrec){
        inrec[u] = true;
        vis[u] = true;
        for(auto v : graph[u]){
            if(!vis[v] && DFS(v, graph, vis, inrec)) return true; //Cycle
            else if(inrec[v] == true) return true;
        }
        inrec[u] = false;  // Nodes in cycle will not be able to mark them false
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> inrec(V, false);

        for(int i=0 ; i<V; i++){
            if(!vis[i]) DFS(i, graph, vis, inrec);
        }
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(inrec[i] == false) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

// BFS Topological Sort (Kahn's Algorithm on Reversed Graph) --> O(V + E) time and O(V + E) space
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        for(int u = 0; u<V; u++){
            for(auto v : graph[u]){
                adj[v].push_back(u);  // Reverse each edge
            }
        }
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
        vector<int> safeNode;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            safeNode.push_back(u);
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
        return safeNode;
    }
};