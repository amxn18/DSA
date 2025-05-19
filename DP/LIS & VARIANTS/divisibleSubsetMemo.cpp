#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> dp(n, 1), prev(n, -1);
            
            int maxSize = 1, maxIndex = 0;
            
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
            
            // Reconstruct subset
            vector<int> result;
            while (maxIndex != -1) {
                result.push_back(nums[maxIndex]);
                maxIndex = prev[maxIndex];
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };
    // # Leetcode Problem: 368 - Largest Divisible Subset
    // # Approach 1: Backtracking (Exponential, O(2^N))
    // # - Try all subsets recursively.
    // # - Keep track of the largest subset found.
    
    // # Approach 2: Dynamic Programming (O(N²))
    // # - Sort nums to maintain order.
    // # - Use dp[i] to store the length of the largest subset ending at i.
    // # - Use prev[i] to track the elements forming the subset.
    // # - Construct the subset using the prev array.
    
    // # Time Complexity:
    // # - Backtracking: O(2^N) (TLE for large N)
    // # - DP Approach: O(N²) (Efficient)
    
    // # Space Complexity:
    // # - Backtracking: O(N) (Recursion depth)
    // # - DP Approach: O(N) (For DP and previous index tracking)
        