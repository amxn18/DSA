#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int fib(int n) {
            // Base case: If n is 0 or 1, return n directly (avoids unnecessary computation)
            if(n <= 1) return n;
    
            // Create a DP array to store computed Fibonacci numbers
            vector<int> dp(n + 1, -1);
    
            // Initialize base values
            dp[0] = 0;
            dp[1] = 1;
    
            // Bottom-up approach to fill the DP table
            for(int i = 2; i <= n; i++){
                dp[i] = dp[i-1] + dp[i-2];  // Fibonacci relation
            }
    
            // Return the nth Fibonacci number
            return dp[n];
        }
    };
    // # LeetCode Problem: 509. Fibonacci Number
    // # Approach: Bottom-Up Dynamic Programming (Tabulation)
    
    // # 1. If n is 0 or 1, return n directly.
    // # 2. Create a DP array to store Fibonacci values.
    // # 3. Initialize dp[0] = 0 and dp[1] = 1 (base cases).
    // # 4. Use a loop from i = 2 to n:
    // #      - Compute dp[i] = dp[i-1] + dp[i-2].
    // # 5. Return dp[n] as the final answer.
    
    // # Time Complexity:  O(n)  -> We compute each Fibonacci number once.
    // # Space Complexity: O(n)  -> We store all Fibonacci numbers in an array.
    
    