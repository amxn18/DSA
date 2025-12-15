#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& vis, int V) {
        vis[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !vis[v]) {
                DFS(v, adj, vis, V);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V, false);
        int ctr = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ctr++;
                DFS(i, adj, vis, V);
            }
        }
        return ctr;
    }
};

// TC O(N) + O(V + 2E)