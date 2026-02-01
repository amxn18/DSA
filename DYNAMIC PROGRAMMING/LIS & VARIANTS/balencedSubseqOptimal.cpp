#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long maxBalancedSubsequenceSum(vector<int>& nums) {
            int n = nums.size();
            map<int, long long> mp; // Stores (nums[i] - i) as key and max sum till that index as value
            long long result = INT_MIN;
    
            for(int i = 0; i < n; i++) {
                auto it = mp.upper_bound(nums[i] - i); // Find the first key greater than (nums[i] - i)
                long long sum = nums[i];
    
                // If there exists a valid key before the current one, use its stored sum
                if(it != mp.begin()) {
                    it--;
                    sum += it->second;
                }
    
                // Store or update the maximum sum for the current (nums[i] - i)
                mp[nums[i] - i] = max(mp[nums[i] - i], sum);
    
                // Remove redundant entries in the map (maintaining only useful values)
                it = mp.upper_bound(nums[i] - i);
                while(it != mp.end() && it->second <= sum) {
                    mp.erase(it++);
                }
    
                // Track the overall max sum
                result = max(result, sum);
            }
    
            return result;
        }
    };
    
//     # Leetcode Problem: Max Balanced Subsequence Sum
// # Approach: Optimized Dynamic Programming with Ordered Map (O(N log N))

// # 1. We use an ordered map where:
// #    - Key: nums[i] - i (tracks balance condition)
// #    - Value: Maximum sum of a balanced subsequence up to this index
// # 2. For each element nums[i]:
// #    - We find the largest valid previous sum using upper_bound.
// #    - We update the current sum based on previous values.
// #    - We maintain the map to store only relevant values by erasing redundant entries.
// # 3. The map helps efficiently retrieve and update the best possible subsequence sum.

// # Time Complexity: O(N log N) (Each insertion/deletion in map takes log N)
// # Space Complexity: O(N) (For storing valid subsequences in the map)
