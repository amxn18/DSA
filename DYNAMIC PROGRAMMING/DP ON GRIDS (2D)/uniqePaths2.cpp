#include <bits/stdc++.h>
using namespace std;

// LC 63
// Method 1: Recursion + Memoization
// TC = O(m*n) and SC = O(m*n) + O(m+n)
class Solution {
public:
    int t[101][101];
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(t[i][j] != -1) return t[i][j];

        int right = solve(i, j+1, grid);
        int down = solve(i+1, j, grid);
        return t[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        return solve(0, 0, obstacleGrid);
    }
};

// Method 2: Bottom-Up DP
// TC = O(m*n) and SC = O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int col=0; col<n; col++){
            if(col >= 1 && obstacleGrid[0][col-1] == 1){
                dp[0][col] = 0;
                obstacleGrid[0][col] = 1;
            }
            else if(obstacleGrid[0][col] == 1) dp[0][col] = 0;
            else dp[0][col] = 1;
        }
        for(int row=0; row<m; row++){
            if(row >= 1 && obstacleGrid[row-1][0] == 1){
                dp[row][0] = 0;
                obstacleGrid[row][0] = 1;
            }
            else if(obstacleGrid[row][0] == 1) dp[row][0] = 0;
            else dp[row][0] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};