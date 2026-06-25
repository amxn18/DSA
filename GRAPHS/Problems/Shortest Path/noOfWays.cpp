#include <bits/stdc++.h>
using namespace std;

// LC 1976  // TC --> O((E+v)*log(V))   SC --> O(V+E) + O(V)
class Solution {
public:
    typedef pair<long long, int> P;
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> times(n, LLONG_MAX);
        vector<int> pathCtr(n, 0);

        priority_queue<P, vector<P>, greater<P>> pq;

        times[0] = 0;
        pathCtr[0] = 1;
        pq.push({0, 0});   // {time, node}

        while (!pq.empty()) {
            auto t = pq.top().first;
            auto u = pq.top().second;
            pq.pop();

            if (t > times[u]) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if (t + wt < times[v]) {
                    times[v] = t + wt;
                    pathCtr[v] = pathCtr[u];
                    pq.push({times[v], v});
                }
                else if (t + wt == times[v]) {
                    pathCtr[v] = (pathCtr[v] + pathCtr[u]) % MOD;
                }
            }
        }
        return pathCtr[n-1];
    }
};
