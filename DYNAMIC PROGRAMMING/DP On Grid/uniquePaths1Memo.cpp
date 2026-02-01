#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dp[101][101];
    
        int solve(int i, int j, int m, int n){
            // Base case: reached destination
            if(i == m-1 && j == n-1) return 1;
    
            // Out of bounds
            if(i >= m || j >= n) return 0;
    
            // Memoization check
            if(dp[i][j] != -1) return dp[i][j];
    
            // Move right and down
            int right = solve(i, j+1, m, n);
            int down = solve(i+1, j, m, n);
    
            return dp[i][j] = right + down;
        }
    
        int uniquePaths(int m, int n) {
            memset(dp, -1, sizeof(dp));  // Initialize DP
            return solve(0, 0, m, n);    // Start from top-left
        }
    };
    
    // # ✅ LeetCode 62. Unique Paths

    // 🧠 Problem:
    // - You are given a grid of size m x n.
    // - Starting from top-left (0,0), you can only move either **right** or **down**.
    // - Count the total number of unique paths to reach the bottom-right corner (m-1,n-1).
    
    // 🛠️ Approach: Top-Down DP (Memoization)
    
    // 1. Define a recursive function `solve(i, j)`:
    //    - Base Case:
    //      - If `i == m-1` and `j == n-1`: return 1 (reached destination)
    //      - If out of bounds: return 0
    //    - Memoization:
    //      - If already computed `dp[i][j]`: return it
    //    - Otherwise:
    //      - Paths = solve(i+1, j) + solve(i, j+1)
    
    // 2. Use a `dp[101][101]` array to memoize answers.
    // 3. Start from (0, 0) to get total unique paths.
    
    // 📦 Code Logic Summary:
    // - From each cell, you either go right or down.
    // - You sum up the number of paths from both choices.
    // - Use memoization to avoid recomputation.
    
    // ⏱️ Time Complexity:
    // - O(m * n)
    //   - Each cell `(i,j)` is visited once due to memoization.
    
    // 🧠 Space Complexity:
    // - O(m * n) for the memoization table
    // - O(m + n) auxiliary stack space due to recursion depth
    
    // 💡 Key Concepts:
    // - Recursion + Memoization
    // - Grid-based DP
    // - Overlapping subproblems
    
    // 🔥 Tip:
    // - You can also solve this using bottom-up DP or combinatorics later for better space optimization.
    
        