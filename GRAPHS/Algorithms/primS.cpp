#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> P; // {weight, node}

    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<P>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> inMST(V, false);
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});  
        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            sum += wt;

            for (auto &it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
        return sum;
    }
};
