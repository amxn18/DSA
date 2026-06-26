#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu; // or parent[pu] = pv
            rank[pu]++; // or rank[pv]++;
        }
    }
};

int main() {}

int findParent(int node, vector<int>& parent){
    if(node == parent[node]) return node; // Parent of node is itself
    return findParent(parent[node], parent); // Recursively find the parent
}
void UnionBasic(int u, int v, vector<int>& parent){
    int parentX = findParent(u, parent);
    int parentY = findParent(v, parent);
    if(parentX != parentY) parent[parentY] = parentX; //(parent[parentX] = parentY) // Union the two sets
}