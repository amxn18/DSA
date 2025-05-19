#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maxBalancedSubsequenceSum(vector<int>& nums) {
            int n = nums.size();
            int maxEl = *max_element(begin(nums), end(nums)); // Find the maximum element in the array
            
            // If all elements are non-positive, return the maximum element
            if (maxEl <= 0) return maxEl;
    
            vector<long long> dp(n); // DP array to store the max balanced subsequence sum at each index
    
            // Initialize DP array with the element itself
            for(int i = 0; i < n; i++) {
                dp[i] = nums[i];
            }
    
            long long maxSum = INT_MIN; // Variable to track the max sum
    
            // Iterate over all elements
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < i; j++) {
                    // Check if nums[i] satisfies the balanced condition relative to nums[j]
                    if(nums[i] - i >= nums[j] - j) {
                        // Update dp[i] with the max sum including nums[i]
                        dp[i] = max<long long>(dp[i], dp[j] + nums[i]);
                        maxSum = max(maxSum, dp[i]); // Update global maxSum
                    }
                }
            }
    
            // Ensure maxSum is at least the largest element in case no valid subsequence is found
            return maxSum > maxEl ? maxSum : maxEl;
        }
    };
    
//     # Leetcode Problem: Max Balanced Subsequence Sum(LC 2926)
// # Approach: Dynamic Programming (Bottom-Up)

// # 1. We use a DP array where dp[i] stores the max balanced subsequence sum ending at index i.
// # 2. The base case initializes dp[i] with nums[i] since any single element is a valid subsequence.
// # 3. We iterate through the array and for each element i:
// #    - Check all previous elements j < i.
// #    - If nums[i] - i >= nums[j] - j (balanced condition), update dp[i].
// # 4. Track the global max sum from dp.
// # 5. If no valid subsequence exists, return the largest element in nums.

// # Time Complexity: O(N^2) (Nested loops iterating over pairs)
// # Space Complexity: O(N) (DP array to store intermediate results)
