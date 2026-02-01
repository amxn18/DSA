#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int dp[2501][2501]; // DP table to store LIS results
    
        int solve(int idx, int prev, vector<int>& nums) {
            if (idx >= n) return 0; // Base case: no more elements left
            
            if (prev != -1 && dp[idx][prev] != -1) return dp[idx][prev]; // Return memoized result
    
            int take = 0;
            if (prev == -1 || nums[prev] < nums[idx]) { // If we can take the current element
                take = 1 + solve(idx + 1, idx, nums);
            }
            int skip = solve(idx + 1, prev, nums); // Skip current element
    
            if (prev != -1) dp[idx][prev] = max(take, skip); // Memoize result
            return max(take, skip); // Return maximum LIS length
        }
    
        int lengthOfLIS(vector<int>& nums) {
            n = nums.size();
            memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
            return solve(0, -1, nums); // Start from index 0 with no previous element
        }
    };

//     # Leetcode 300 - Longest Increasing Subsequence (LIS)
// # Approach: Top-Down Dynamic Programming (Memoization)

// # 1. We define a recursive function `solve(idx, prev)`, where:
// #    - `idx` is the current index.
// #    - `prev` is the index of the last included element.
// # 2. Base Case:
// #    - If `idx >= n`, return 0.
// # 3. Transition:
// #    - If `nums[prev] < nums[idx]`, we have two choices:
// #      - Take the current element: `1 + solve(idx+1, idx)`.
// #      - Skip the current element: `solve(idx+1, prev)`.
// #    - Memoize the result to avoid recomputation.
// # 4. The final answer is `solve(0, -1)`.

// # Time Complexity: O(N^2)  -> We process each (idx, prev) pair.
// # Space Complexity: O(N^2) -> We use a 2D DP table.

    