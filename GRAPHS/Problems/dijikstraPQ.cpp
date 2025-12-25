#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<P>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // undirected graph
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto v: adj[u]) {
                if (d + v.second < dist[v.first]) {
                    dist[v.first] = d + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        return dist;
    }
};
