#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(begin(nums), end(nums));
            vector<int> dp(n, 1);   // dp[i] stores the length of the largest divisible subset ending at index i
            vector<int> prev(n, -1); // prev[i] stores the previous index in the subset
    
            int lastIdx = 0; // Track the index of the largest element in the subset
            int maxEl = 1;    // Maximum subset length found
    
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if(dp[i] > maxEl){
                    maxEl = dp[i];
                    lastIdx = i;
                }
            }
    
            vector<int> result;
            while(lastIdx != -1){
                result.push_back(nums[lastIdx]);
                lastIdx = prev[lastIdx];
            }
    
            reverse(result.begin(), result.end()); // Reverse to get the correct order
            return result;
        }
    };
    
//     # Leetcode Problem: 368 - Largest Divisible Subset
// # Approach: Dynamic Programming (O(N²))

// # Fix for Single-Element Case:
// # - If nums has only one element, lastIdx should not be -1.
// # - Initialize lastIdx to 0 so that nums[0] is included.

// # Steps:
// # 1. Sort nums[] to ensure divisibility order.
// # 2. Use dp[i] to track the length of the largest subset ending at index i.
// # 3. Use prev[i] to store the previous index in the subset.
// # 4. Iterate over all pairs (i, j) where j < i:
// #    - If nums[i] % nums[j] == 0, update dp[i] and prev[i].
// # 5. Find the index of the largest subset, then reconstruct the subset using prev[].
// # 6. Reverse the result to return it in correct order.

// # Time Complexity: O(N²) (Nested loops for subset calculation)
// # Space Complexity: O(N) (DP and prev tracking)
