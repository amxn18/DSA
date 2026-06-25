#include <bits/stdc++.h>
using namespace std;

// LC 787  TC O(E*n) + O(E)  SC O(E+n)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto vec : flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;
        int steps = 0;
        while(!q.empty() && steps <= k){
            int N = q.size();
            while(N--){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for(auto it : adj[u]){
                    int v = it.first;
                    int dist = it.second;

                    if(d + dist < distance[v]){
                        distance[v] = d + dist;
                        q.push({v, d+dist});
                    }
                }
            }
            steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};