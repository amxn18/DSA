#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Create a 2D DP array of size m x n
            vector<vector<int>> dp(m, vector<int>(n));
    
            // Fill the first row with 1s since there's only one way to move right
            for (int col = 0; col < n; col++) {
                dp[0][col] = 1;
            }
    
            // Fill the first column with 1s since there's only one way to move down
            for (int row = 0; row < m; row++) {
                dp[row][0] = 1;
            }
    
            // Fill the rest of the DP table
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    // The number of ways to reach cell (i,j) is the sum of
                    // ways to reach from the top cell and from the left cell
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
    
            // Return the value in the bottom-right corner of the grid
            return dp[m - 1][n - 1];
        }
    };
    

// # ✅ Leetcode 62. Unique Paths (Bottom-Up DP)

// 🧠 Problem:
// - Given an m x n grid, find the number of unique paths from top-left to bottom-right.
// - Only moves allowed: RIGHT or DOWN.

// 🛠️ Approach: Bottom-Up Dynamic Programming

// 1. Create a 2D dp table `dp[m][n]`:
//    - `dp[i][j]` stores the number of unique ways to reach cell `(i,j)`

// 2. Base Conditions:
//    - First row (0th row) → Only one way to move → All `dp[0][col] = 1`
//    - First column (0th col) → Only one way to move → All `dp[row][0] = 1`

// 3. Fill the rest of the grid:
//    - For each cell `(i,j)`, you can come either from:
//      - Top cell: `dp[i-1][j]`
//      - Left cell: `dp[i][j-1]`
//    - So, `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

// 4. Final answer → `dp[m-1][n-1]`


