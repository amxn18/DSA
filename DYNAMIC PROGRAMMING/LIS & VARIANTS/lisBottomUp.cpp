#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, 1); // DP array initialized with 1
            int maxLis = 1; // Variable to store the max LIS length
    
            for(int i = 0; i < n; i++) { // Iterate through elements
                for(int j = 0; j < i; j++) { // Check all previous elements
                    if(nums[j] < nums[i]) { // Increasing order check
                        dp[i] = max(dp[i], dp[j] + 1); // Update dp[i]
                        maxLis = max(maxLis, dp[i]); // Update max LIS length
                    }
                }
            }
            return maxLis; // Return maximum LIS found
        }
    };
    
//     # Leetcode 300 - Longest Increasing Subsequence (LIS)
// # Approach: Bottom-Up Dynamic Programming (Tabulation)

// # 1. Define `dp[i]` as the length of LIS ending at index `i`.
// # 2. Initialize: `dp[i] = 1` (each element alone is an LIS of length 1).
// # 3. Transition:
// #    - For every `i`, check all previous elements `j < i`.
// #    - If `nums[j] < nums[i]`, update `dp[i] = max(dp[i], dp[j] + 1)`.
// #    - Keep track of the max LIS length (`maxLis`).
// # 4. Return `maxLis`, the longest increasing subsequence length.

// # Time Complexity: O(N^2)  -> Two nested loops.
// # Space Complexity: O(N)   -> We use a single dp array.
