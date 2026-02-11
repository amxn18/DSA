#include <bits/stdc++.h>
using namespace std;

// LC 62
// Method 1: Recursion + Memoization
// TC = O(m*n) and SC = O(m*n) + O(m+n)

class Solution {
public:
    int t[101][101];
    int solve(int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(t[i][j] != -1) return t[i][j];
        int goDown = solve(i+1, j, m, n);
        int goRight = solve(i, j+1, m, n);
        return t[i][j] = goDown + goRight;
    }
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, m, n);
    }
};

// Method 2: Bottom-Up DP
// TC = O(m*n) and SC = O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int col=0; col<n; col++){
            dp[0][col] = 1;
        }
        for(int row=0; row<m; row++){
            dp[row][0] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

