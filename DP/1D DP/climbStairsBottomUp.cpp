#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            // Base cases for small values of n
            if(n == 1 || n == 2 || n == 3) return n;
            
            vector<int> dp(n+1, -1); // DP array to store the number of ways
            dp[0] = 0;  // Not needed, but initialized for completeness
            dp[1] = 1;  // Only 1 way to reach step 1
            dp[2] = 2;  // Two ways to reach step 2 (1+1 or 2)
            
            // Iteratively calculate the number of ways for each step
            for(int i = 3; i <= n; i++) {
                dp[i] = dp[i-1] + dp[i-2]; // Transition relation
            }
            
            return dp[n]; // Return the final answer
        }
    };

    
    // # Climbing Stairs (Leetcode 70) - Bottom-Up DP (Tabulation)

    // ## Problem Statement:
    // # Given `n` steps, you can take 1 or 2 steps at a time.
    // # Find the number of distinct ways to climb to the top.
    
    // ## Approach:
    // # - Use **Bottom-Up DP** with an array to store results for subproblems.
    // # - Define a `dp` array where `dp[i]` represents ways to reach step `i`.
    // # - Base cases:
    // #   - `dp[1] = 1`  (1 way to reach step 1)
    // #   - `dp[2] = 2`  (2 ways: (1,1) or (2))
    // # - Fill `dp` using the recurrence relation:
    // #   - `dp[i] = dp[i-1] + dp[i-2]`
    // # - Return `dp[n]` as the final answer.
    
    // ## Time Complexity:
    // # - O(n) -> We iterate once from 3 to `n`.
    
    // ## Space Complexity:
    // # - O(n) -> Due to the DP array.
    
    // ## Alternative Approaches:
    // # - **Top-Down DP (Memoization)** (O(n) time, O(n) space due to recursion stack).
    // # - **Space-Optimized DP** reduces space to **O(1)** by keeping only two variables.
    