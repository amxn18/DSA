#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            int n = pairs.size();
            vector<int> dp(n, 1); // DP array initialized to 1
            sort(begin(pairs), end(pairs)); // Sort pairs based on first element
            int maxLis = 1; // Stores maximum LIS length
    
            // Iterate over pairs
            for(int i = 0; i < n; i++) { 
                for(int j = 0; j < i; j++) { 
                    // If pair[j]'s end < pair[i]'s start, we can extend the chain
                    if(pairs[j][1] < pairs[i][0]) { 
                        dp[i] = max(dp[i], dp[j] + 1); 
                        maxLis = max(maxLis, dp[i]); // Track max LIS found
                    }
                }
            }
            return maxLis; // Return maximum chain length
        }
    };
//     # Leetcode 646 - Maximum Length of Pair Chain
// # Approach: Bottom-Up DP (Tabulation)

// # 1. Sort pairs based on the first element.
// # 2. Initialize a DP array dp[n] where dp[i] = 1 (each pair is a chain of at least 1).
// # 3. Iterate over pairs:
// #    - For each i, check all previous j < i.
// #    - If pairs[j][1] < pairs[i][0], update dp[i] = max(dp[i], dp[j] + 1).
// #    - Track max chain length.
// # 4. Return maxLis (longest chain found).

// # Time Complexity: O(N^2)  -> DP transitions.
// # Space Complexity: O(N)   -> DP array.
