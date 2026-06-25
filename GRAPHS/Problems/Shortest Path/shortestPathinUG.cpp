#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> P;

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        vector<vector<P>> adj(n + 1);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        int destination = n;
        if (dist[destination] == INT_MAX)
            return {-1};

        vector<int> path;
        int node = destination;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());
        return path;
    }
};
