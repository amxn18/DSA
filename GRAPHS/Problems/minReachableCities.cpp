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

// Using Floyd Warshall TC O(n³)   SC O(n²)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // Src -> Src : Dist = 0
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            // Bidirectional 
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        int city = -1;
        int minCount = INT_MAX;
        for(int i=0; i<n; i++){
            int ctr = 0;
            for(int j=0; j<n; j++){
                if(i != j && dist[i][j] <= distanceThreshold) ctr++;
            }
            if(ctr <= minCount){
                minCount = ctr;
                city = i;
            }
        }
        return city;

    }
};

