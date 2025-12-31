#include <bits/stdc++.h>
using namespace std;

// LC 1334
// Using Dijikstra TC O(n × (n + m) log n)   SC O(n²)
class Solution {
public:
    void dijkstra(int n,
                  vector<vector<pair<int,int>>>& adj,
                  vector<int>& dist,
                  int src) {

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        fill(dist.begin(), dist.end(), INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d  = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, dist[i], i);
        }

        int ans = -1;
        int minCnt = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                ans = i;  
            }
        }
        return ans;
    }
};

