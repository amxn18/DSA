#include <bits/stdc++.h>
using namespace std;

// LC 886. Possible Bipartition
// TC O(n + m) SC O(n + m) where n is number of peple and m is number of dislike pairs
class Solution {
public:
    bool DFS(int u, vector<vector<int>>& adj, vector<int>& whichGroup, int currGroupNum){
        whichGroup[u] = currGroupNum;
        for(auto &v : adj[u]){
            if(whichGroup[v] == currGroupNum) return false;
            if(whichGroup[v] == -1){
                int groupNumOfV = 1 - whichGroup[u];
                if(DFS(v, adj, whichGroup, groupNumOfV) == false) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1); // Nodes 1->n
        for(auto edge: dislikes){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> whichGroup(n+1, -1); // 1->n
        for(int i=0; i<n; i++){
            if(whichGroup[i] == -1){
                if(DFS(i, adj, whichGroup, 0) == false) return false;
            }
        }
        return true;
    }
};