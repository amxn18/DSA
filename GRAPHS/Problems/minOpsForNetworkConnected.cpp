#include <bits/stdc++.h>
using namespace std;

// LC 1319
// TC O(m) m = connections.size();
// SC O(n) n = no of nodes/computers
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int comp = n;
        for(auto vec : connections){
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0], vec[1]);
                comp--;
            }
        }
        return comp-1;
    }

};