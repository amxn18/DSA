#include <bits/stdc++.h>
using namespace std;

// TC O(4^m*n)
// SC O(m*n)

class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>>& m, vector<string>& ans, 
               vector<vector<int>>& vis, string path){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        // Down
        if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1){
            vis[i+1][j] = 1;
            solve(i+1, j, n, m, ans, vis, path + 'D');
            vis[i+1][j] = 0;
        }
        // Left
        if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1){
            vis[i][j-1] = 1;
            solve(i, j-1, n, m, ans, vis, path + 'L');
            vis[i][j-1] = 0;
        }
        // Right
        if(j+1 < n && !vis[i][j+1] && m[i][j+1] == 1){
            vis[i][j+1] = 1;
            solve(i, j+1, n, m, ans, vis, path + 'R');
            vis[i][j+1] = 0;
        }
        // Up
        if(i-1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1){
            vis[i-1][j] = 1;
            solve(i-1, j, n, m, ans, vis, path + 'U');
            vis[i-1][j] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(maze[0][0] == 1){
            vis[0][0] = 1;  // mark start as visited
            solve(0, 0, n, maze, ans, vis, "");
        }
        return ans;
    }
};
