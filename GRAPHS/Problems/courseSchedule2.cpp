#include <bits/stdc++.h>
using namespace std;

// LC 210. Course Schedule II
// BFS Topological Sort --> O(V + E) time and O(V + E) space
class Solution {
public:
    vector<int> toposort(int n, unordered_map<int, vector<int>>& adj, vector<int>& indeg){
        vector<int> result;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        int ctr = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            ctr++;
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
        if(ctr == n) return result;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(numCourses, 0);
        for(auto vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indeg[a]++;
        }
        return toposort(numCourses, adj, indeg);
    }
};

// DFS Topological Sort --> O(V + E) time and O(V + E) space

class Solution {
public:
    bool hasCycle = false;

    void DFS(int u,
             unordered_map<int, vector<int>>& adj,
             vector<bool>& inrec,
             vector<bool>& vis,
             stack<int>& st) {

        if (hasCycle) return;

        vis[u] = true;
        inrec[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                DFS(v, adj, inrec, vis, st);
            }
            else if (inrec[v]) {
                hasCycle = true;
                return;
            }
        }

        inrec[u] = false;
        st.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for (auto& vec : prerequisites) {
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> inrec(numCourses, false);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                DFS(i, adj, inrec, vis, st);
            }
        }

        if (hasCycle) return {};

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
