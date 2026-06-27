#include <bits/stdc++.h>
using namespace std;

// LC 1584 
//TC = O(V² log V)
//SC = O(V²)
class Solution {
public:
    typedef pair<int,int> P; 

    int primsAlgo(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(V, false);

        int sum = 0;
        pq.push({0, 0});   

        while (!pq.empty()) {
            int wt  = pq.top().first;
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1= points[i][0];
                int y1 = points[i][1];

                int x2= points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);
        
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return primsAlgo(adj, V);
    }
};
