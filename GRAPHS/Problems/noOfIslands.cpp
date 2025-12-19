#include <bits/stdc++.h>
using namespace std;

// LC 200: Number of Islands
// TC  : O(m*n) , SC : O(1) [ignoring recursion stack space]
class Solution {
public: 
    int m, n;
    vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFS(int i, int j, vector<vector<char>>& grid){
        m = grid.size();
        n = grid[0].size();
        grid[i][j] = '!';
        for(auto dir : dirs){
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == '1') DFS(newI, newJ, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ctr = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    DFS(i, j, grid);
                    ctr++;
                }
            }
        }
        return ctr;
    }
};