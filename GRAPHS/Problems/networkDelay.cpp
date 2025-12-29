#include <bits/stdc++.h>
using namespace std;

// LC 743
class Solution {
public:
    typedef pair<int,int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> adj(n + 1);
        for (auto &vec : times) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[k] = 0;
        pq.push({0, k});   // {distance, node}
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
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
