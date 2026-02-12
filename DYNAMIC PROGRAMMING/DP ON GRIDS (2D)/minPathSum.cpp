#include <bits/stdc++.h>
using namespace std;

// LC 64
// Method 1: Recursion + Memoization
// TC = O(m*n) and SC = O(m*n) + O(m+n)

class Solution {
public:
    int t[201][201];
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j == n-1) return grid[i][j];
        if(t[i][j] != -1) return t[i][j];

        int right = solve(grid, i,j+1);
        int down = solve(grid, i+1, j);

        return t[i][j] = grid[i][j] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0);
    }
};

// Method 2: Bottom-Up DP
// TC = O(m*n) and SC = O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int col=1; col<n; col++) dp[0][col] = grid[0][col] + dp[0][col-1];
        for(int row=1; row<m; row++) dp[row][0] = grid[row][0] + dp[row-1][0];
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};