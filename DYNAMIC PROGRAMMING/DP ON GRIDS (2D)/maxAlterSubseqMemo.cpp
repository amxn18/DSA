#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        typedef long long ll;
        int n;
        ll dp[1000001][2]; // Memoization table for storing computed results
    
        // Recursive function to compute maximum alternating sum
        ll solve(int idx, vector<int>& nums, bool flag) {
            if (idx >= n) return 0; // Base case: No elements left to choose
    
            if (dp[idx][flag] != -1) return dp[idx][flag]; // Return if already computed
    
            ll skip = solve(idx + 1, nums, flag); // Case 1: Skip current element
            ll val = nums[idx];
            if (flag == false) val = -val; // Negate value if flag is false
    
            ll take = solve(idx + 1, nums, !flag) + val; // Case 2: Take current element and toggle flag
    
            return dp[idx][flag] = max(take, skip); // Store and return max result
        }
    
        long long maxAlternatingSum(vector<int>& nums) {
            n = nums.size();
            memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
            return solve(0, nums, true); // Start with first element (positive sign)
        }
    };


//     # Leetcode 1911 - Maximum Alternating Subsequence Sum
// # Approach: Top-Down Dynamic Programming (Recursion + Memoization)

// # 1. We use a recursive function `solve(idx, flag)`:
// #    - `idx` is the current position in the array.
// #    - `flag` determines whether to add (true) or subtract (false) the element.
// # 2. At each step, we have two choices:
// #    - Skip the element and move to the next.
// #    - Take the element, modify its sign based on `flag`, and proceed.
// # 3. We use a 2D `dp` array to store previously computed results.
// # 4. Base case: If `idx >= n`, return 0 (no elements left).
// # 5. Start from `idx = 0` with `flag = true`.

// # Time Complexity: O(N)  -> Each state (idx, flag) is visited once.
// # Space Complexity: O(N) -> 2D DP array + recursion stack.

    