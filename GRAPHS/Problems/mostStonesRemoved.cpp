#include <bits/stdc++.h>
using namespace std;

// LC 947
// TC O(nxn)
// SC O(n)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) return;
        if(rank[xp] > rank[yp]) parent[yp] = xp;
        else if(rank[yp] > rank[xp]) parent[xp] = yp;
        else{
            parent[yp] = xp;
            rank[xp]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) Union(i, j);
            }
        }
        int grps = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) grps++;
        }
        return n-grps;
    }
};