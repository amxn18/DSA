#include <bits/stdc++.h>
using namespace std;

// LC 990
// TC: O(N * α(N)) where α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical purposes.
// SC: O(1)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        rank.resize(26, 0);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(string &s: equations){
            if(s[1] == '=') Union(s[0] - 'a', s[3] - 'a'); // DSU needs indices
        }
        for(string &s: equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];
                int parentF = find(first - 'a');
                int parentS = find(second - 'a');

                if(parentF == parentS) return false; // Means they are actually equal but there is !
            }
        }
        return true;
    }
};