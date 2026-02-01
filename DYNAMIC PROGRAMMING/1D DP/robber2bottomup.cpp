#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0]; // Edge case: Only one house
            
            vector<int> dp(n+1, 0);
            
            // Case 1: Rob from house 0 to n-2 (Skip last house)
            dp[0] = 0;
            for (int i = 1; i <= n-1; i++) {
                int skip = dp[i-1]; // Don't rob current house
                int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0); // Rob current house
                dp[i] = max(steal, skip);
            }
            int result1 = dp[n-1]; // Maximum loot if we skip the last house
    
            // Reinitialize dp for the second case
            dp.assign(n+1, 0);
    
            // Case 2: Rob from house 1 to n-1 (Skip first house)
            dp[1] = 0;
            for (int i = 2; i <= n; i++) {
                int skip = dp[i-1]; // Don't rob current house
                int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0); // Rob current house
                dp[i] = max(steal, skip);
            }
            int result2 = dp[n]; // Maximum loot if we skip the first house
    
            return max(result1, result2); // Take max of both cases
        }
    };


    // # Leetcode 213: House Robber II

    // ## Problem Statement:
    // # A thief plans to rob houses in a **circular** neighborhood. Since the houses
    // # are arranged in a circle, robbing the **first and last house together is not allowed**.
    // # The goal is to maximize the total amount stolen.
    
    // ## Approach (Bottom-Up DP):
    // # Since the first and last house cannot be robbed together, we solve the problem **twice**:
    // #   1. **Exclude the last house** → Consider houses from index **0 to n-2**.
    // #   2. **Exclude the first house** → Consider houses from index **1 to n-1**.
    // # The final answer is the **maximum of both cases**.
    
    // ## Dynamic Programming Transition:
    // # dp[i] = max(dp[i-1], nums[i] + dp[i-2])
    // # This means:
    // #   - Either **skip the current house** (dp[i-1])
    // #   - Or **rob the current house** (nums[i] + dp[i-2])
    
    // ## Time Complexity:
    // # O(N) - We compute the DP table twice, but each run takes O(N).
    
    // ## Space Complexity:
    // # O(N) - We use an auxiliary DP array of size N.
    
    
    