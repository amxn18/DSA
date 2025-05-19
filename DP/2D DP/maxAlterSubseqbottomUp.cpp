#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long maxAlternatingSum(vector<int>& nums) {
            long long n = nums.size();
            vector<vector<long>> dp(n+1, vector<long>(2, 0)); // DP table: dp[i][0] -> even, dp[i][1] -> odd
            
            for(int i = 1; i <= n; i++) {
                dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]); // Even index case
                dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]); // Odd index case
            }
            
            return max(dp[n][0], dp[n][1]); // Maximum alternating sum
        }
    };
    

    // # Leetcode 1911 - Maximum Alternating Subsequence Sum
    // # Approach: Bottom-Up Dynamic Programming (Tabulation)
    
    // # 1. We maintain a 2D DP table `dp[n+1][2]`:
    // #    - dp[i][0]: Max alternating sum ending at index `i` with an even index.
    // #    - dp[i][1]: Max alternating sum ending at index `i` with an odd index.
    // # 2. At each index `i`, we update:
    // #    - dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]) # Even case (subtract)
    // #    - dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]) # Odd case (add)
    // # 3. The final answer is max(dp[n][0], dp[n][1]).
    
    // # Time Complexity: O(N)  -> We iterate through the array once.
    // # Space Complexity: O(N) -> We store a 2D DP table.
    