#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int dp[1001][1001];
    
        // Recursive function with memoization
        int solve(int idx, int prev, vector<vector<int>>& pairs) {
            if (idx >= n) return 0; // Base case: No more pairs left
    
            if (prev != -1 && dp[idx][prev] != -1) return dp[idx][prev]; // Use cached result
    
            int take = 0;
            // If we can take the current pair (prev == -1 means it's the first element)
            if (prev == -1 || pairs[prev][1] < pairs[idx][0]) { 
                take = 1 + solve(idx + 1, idx, pairs);
            }
            int skip = solve(idx + 1, prev, pairs); // Skip current pair
    
            if (prev != -1) dp[idx][prev] = max(take, skip); // Store result
            return max(take, skip);
        }
    
        int findLongestChain(vector<vector<int>>& pairs) {
            n = pairs.size();
            memset(dp, -1, sizeof(dp)); // Initialize DP array
            sort(begin(pairs), end(pairs)); // Sort pairs based on start time
            return solve(0, -1, pairs); // Start recursion
        }
    };

    // # Leetcode 646 - Maximum Length of Pair Chain
    // # Approach: Top-Down DP (Memoization)
    
    // # 1. Sort the pairs to ensure order.
    // # 2. Define recursive function `solve(idx, prev)`:
    // #    - Base Case: If idx >= n, return 0.
    // #    - If the state is computed, return dp[idx][prev].
    // #    - Two choices:
    // #      a) Take: If valid (prev pair's end < current pair's start), increment count.
    // #      b) Skip: Move to the next index.
    // #    - Store and return max(take, skip).
    // # 3. Start from `idx = 0` and `prev = -1` (no previous element).
    // # 4. Return the maximum chain length.
    
    // # Time Complexity: O(N^2)  -> Sorting + Recursive DP.
    // # Space Complexity: O(N^2) -> DP table.
    
    