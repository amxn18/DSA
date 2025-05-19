#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        int solve(vector<int>& nums, int i, vector<int>& dp) {
            if (i >= nums.size()) return 0;
            if (dp[i] != -1) return dp[i];
    
            int steal = nums[i] + solve(nums, i + 2, dp);
            int leave = solve(nums, i + 1, dp);
    
            return dp[i] = max(steal, leave);
        }
    
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
    
            vector<int> dp1(n, -1), dp2(n, -1);
    
            // Case 1: Rob houses from index 0 to n-2
            vector<int> nums1(nums.begin(), nums.end() - 1);
            int take0Th = solve(nums1, 0, dp1);
    
            // Case 2: Rob houses from index 1 to n-1
            vector<int> nums2(nums.begin() + 1, nums.end());
            int leave0Th = solve(nums2, 0, dp2);
    
            return max(take0Th, leave0Th);
        }
    };
    



// # Problem: House Robber II (LeetCode 213)
// # Approach: Dynamic Programming with Memoization (Top-Down)
// # Time Complexity: O(N)
// # Space Complexity: O(N) (due to recursion and DP array)

// # Explanation:
// # - The thief cannot rob two adjacent houses.
// # - The houses are arranged in a circle, meaning the first and last houses are adjacent.
// # - We solve this by considering two cases:
// #   1. Robbing from house 0 to n-2 (excluding the last house).
// #   2. Robbing from house 1 to n-1 (excluding the first house).
// # - For both cases, we use recursion with memoization.
// # - We then return the maximum profit from both cases.

// # Breakdown:
// # 1. The solve function is a recursive function with memoization:
// #    - Base case: If index >= size of the array, return 0.
// #    - If already computed, return stored value.
// #    - Otherwise, choose between stealing the current house or skipping it.
// #    - Store and return the max profit.
// # 2. In rob():
// #    - If there’s only one house, return its value.
// #    - Otherwise, create two DP arrays for the two cases.
// #    - Solve for both cases and return the maximum profit.

// # Edge Cases Considered:
// # - Single house
// # - All houses have the same value
// # - Large inputs (to test efficiency)
