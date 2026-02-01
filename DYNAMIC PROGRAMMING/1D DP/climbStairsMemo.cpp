#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Recursive function with memoization
        int solve(int n, vector<int>& dp){
            if(n < 0) return 0;  // If steps go below zero, not a valid path
            if(n == 0) return 1; // If exactly 0 steps left, found a valid way
            if(dp[n] != -1) return dp[n]; // Return precomputed result if available
    
            // Store and return the number of ways to reach the top
            return dp[n] = solve(n-1, dp) + solve(n-2, dp);
        }
        
        int climbStairs(int n) {
            if(n < 0) return 0;  // Invalid case
            if(n == 0) return 1;  // Base case
    
            vector<int> dp(n+1, -1); // DP array initialized with -1
            return solve(n, dp);
        }
    };

    
    // # Climbing Stairs (Leetcode 70) - Top-Down DP (Memoization)

    // ## Problem Statement:
    // # Given `n` steps, you can take 1 or 2 steps at a time.
    // # Find the number of distinct ways to climb to the top.
    
    // ## Approach:
    // # - Use recursion with memoization to avoid redundant calculations.
    // # - Define a recursive function solve(n, dp) that:
    // #   - Returns 1 if `n == 0` (valid way found).
    // #   - Returns 0 if `n < 0` (invalid path).
    // #   - If already computed, return stored result from dp array.
    // #   - Otherwise, compute the result as `solve(n-1) + solve(n-2)`, store in dp[n].
    
    // ## Time Complexity:
    // # - O(n) -> Each state (step count) is solved only once.
    
    // ## Space Complexity:
    // # - O(n) -> Due to the recursion stack + DP array.
    
    // ## Alternative Approaches:
    // # - Bottom-Up DP (Tabulation) reduces recursion overhead.
    // # - Space-Optimized DP reduces space to O(1) by storing only last two values.
        