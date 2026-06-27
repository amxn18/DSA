#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) where E is the number of edges and V is the number of vertices. The priority queue operations take logarithmic time, and we process each edge once.
// SC: O(V + E) for the adjacency list and the priority queue.
class Solution {
  public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge: edges){
            int u = edge[0]; 
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(inMST[u] == true) continue;
            inMST[u] = true;
            sum += wt;
            for(auto it: adj[u]){
                int v = it.first;
                int dist = it.second;
                if(inMST[v] == false) pq.push({dist, v});
            }
        }
        return sum;
    }
};