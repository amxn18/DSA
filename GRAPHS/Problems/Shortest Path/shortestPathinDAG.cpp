#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void topoDFS(int u,
                 vector<vector<pair<int,int>>>& adj,
                 vector<bool>& vis,
                 stack<int>& st) {
        vis[u] = true;
        for (auto &it : adj[u]) {
            int v = it.first;
            if (!vis[v]) {
                topoDFS(v, adj, vis, st);
            }
        }
        st.push(u);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoDFS(i, adj, vis, st);
            }
        }
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (dist[u] == INT_MAX) continue;
            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
