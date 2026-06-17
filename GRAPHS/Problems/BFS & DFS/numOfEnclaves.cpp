#include <bits/stdc++.h>
using namespace std;

// LC 1020 . Number of Enclaves
// TC O(m*n) SC O(m*n)
class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFS(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;
        for(auto dir : dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni >=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj] == 1) DFS(ni, nj, vis, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            if(!vis[0][j] && grid[0][j] == 1) DFS(0, j, vis, grid);
            if(!vis[m-1][j] && grid[m-1][j] == 1) DFS(m-1, j, vis, grid);
        }
        for(int i=0; i<m; i++){
            if(!vis[i][0] && grid[i][0] == 1) DFS(i, 0, vis, grid);
            if(!vis[i][n-1] && grid[i][n-1] == 1) DFS(i, n-1, vis, grid);
        }
        int ctr = 0;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1) ctr++;
            }
        }
        return ctr;
    }
};