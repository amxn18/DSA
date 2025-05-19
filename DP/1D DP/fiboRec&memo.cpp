#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Recursive function with memoization (Top-Down DP)
        int solve(int n, vector<int>& dp){
            if(n<=1) return n; // Base case: F(0) = 0, F(1) = 1
            
            if(dp[n] != -1) // If already computed, return stored value
                return dp[n];
    
            // Store and return the result of the recursive relation: F(n) = F(n-1) + F(n-2)
            return dp[n] = solve(n-1, dp) + solve(n-2, dp);
        }
    
        int fib(int n) {
            if(n<=1) return n; // Base case
    
            vector<int> dp(n+1, -1); // DP array initialized to -1 (for memoization)
           
            return solve(n, dp); // Start recursion
        }
    };

    // # Leetcode 509: Fibonacci Number
    // # --------------------------------
    // # Approach: Recursion + Memoization (Top-Down DP)
    // # -----------------------------------------------
    // # 1. Base case: If n <= 1, return n (F(0) = 0, F(1) = 1).
    // # 2. Create a DP array (vector<int>) of size (n+1) initialized to -1.
    // # 3. If a value is already computed (dp[n] != -1), return the stored value.
    // # 4. Otherwise, compute F(n) = F(n-1) + F(n-2) and store the result in dp[n].
    // # 5. The main function initializes the DP array and starts the recursive function.
    // # --------------------------------
    // # Time Complexity: O(n)  -> Each subproblem is solved once (memoization avoids redundant calls).
    // # Space Complexity: O(n) -> Recursion stack space + DP array storage.
    