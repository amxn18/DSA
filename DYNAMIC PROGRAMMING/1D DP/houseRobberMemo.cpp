#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        // Recursive function to find the maximum amount that can be robbed
        int solve(vector<int>& nums, int i, vector<int>& dp){
            if(i >= nums.size()) return 0;  // Base case: If index goes out of bounds, return 0
            if(dp[i] != -1) return dp[i];   // If already computed, return stored value
    
            // Option 1: Rob the current house and move to the house at i+2
            int steal = nums[i] + solve(nums, i+2, dp);
            // Option 2: Skip the current house and move to the next house
            int leave = solve(nums, i+1, dp);
    
            // Store the maximum amount that can be robbed from this index
            return dp[i] = max(steal, leave);
        }
    
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+1, -1); // Memoization table initialized to -1
            return solve(nums, 0, dp); // Start from the 0th index
        }
    };

//     # House Robber Problem (Leetcode 198) - Memoization Approach

// # 🏠 Problem:
// # - Given an array `nums` where `nums[i]` represents money in the i-th house.
// # - Cannot rob adjacent houses.
// # - Find the **maximum money** that can be robbed.

// # 🔹 Approach:
// # - Use recursion with memoization (Top-Down DP).
// # - At each house `i`, decide:
// #   1️⃣ Rob the house and move to index `i+2`
// #   2️⃣ Skip the house and move to index `i+1`
// # - Store results in `dp` to avoid recomputation.

// # 📌 Complexity:
// # - **Time Complexity:** O(N) → Each state is computed once.
// # - **Space Complexity:** O(N) (due to recursion stack + dp array).

// # ✅ Example:
// # nums = [2,7,9,3,1]
// # Output: 12
// # Explanation: Rob house 1 (7) + house 3 (3) + house 5 (1) = 12.
