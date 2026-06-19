#include <bits/stdc++.h>
using namespace std;

// LC 207. Course Schedule I
// BFS --> TC O(V + E) , SC O(V + E)

class Solution {
public:
    bool checkUsingTopoSort(unordered_map<int, vector<int>>& adj, vector<int>& indeg, int n){
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        int ctr = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ctr++;
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
        if(ctr == n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        unordered_map<int, vector<int>> adj;   // u --> {v1, v2 /....}
        for(auto vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a); // b-->a
            indeg[a]++;
        }
        return checkUsingTopoSort(adj, indeg, numCourses);
    }
};

// DFS --> TC O(V + E) , SC O(V + E)
class Solution {
public:
    bool checkUsingDFS(unordered_map<int, vector<int>>& adj, vector<bool>& inrec, vector<bool>& vis, int u){
        inrec[u] = true;
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v] && checkUsingDFS(adj, inrec, vis, v)) return true;
            else if(inrec[v] == true) return true;
        }
        inrec[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> inrec(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!vis[i] && checkUsingDFS(adj, inrec, vis, i)) return false; // Means There is a cycle 
        }
        return true; // Means there is no cycle and we can complete all the courses
    }
};