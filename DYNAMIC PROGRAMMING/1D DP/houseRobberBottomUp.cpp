#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            
            // If there's only one house, return its value
            if (n == 1) return nums[0];
    
            // DP array to store the max profit till each house
            vector<int> dp(n + 1, 0);
    
            // Base cases
            dp[0] = 0;         // No houses -> 0 profit
            dp[1] = nums[0];   // Only one house -> rob it
    
            // Fill the dp array using bottom-up approach
            for (int i = 2; i <= n; i++) {
                int steal = nums[i - 1] + dp[i - 2]; // Rob current house and add previous non-adjacent max
                int skip = dp[i - 1];               // Skip current house and take previous max
                dp[i] = max(steal, skip);           // Take max of both choices
            }
    
            return dp[n]; // Return max profit
        }
    };

 
// # Leetcode 198 - House Robber
// # Approach: Dynamic Programming (Tabulation)
// # Time Complexity: O(N)  # Iterates through the list once
// # Space Complexity: O(N) # Uses a DP array of size N+1
// # Explanation:
// # - Use a DP array where dp[i] stores the max amount robbed from first 'i' houses.
// # - Transition formula: dp[i] = max(nums[i-1] + dp[i-2], dp[i-1])
// # - Base cases: dp[0] = 0, dp[1] = nums[0]
// # - Final answer is stored in dp[n].

    