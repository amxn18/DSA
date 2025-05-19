#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        unordered_map<string, long long> mp; // Memoization using a map to store computed values
    
        // Recursive function to find the max balanced subsequence sum
        long long solve(int prev, int idx, vector<int>& nums) {
            // Base case: If index exceeds array size, return 0
            if (idx >= nums.size()) return 0;
    
            // Creating a unique key for memoization
            string key = to_string(prev) + "_" + to_string(idx);
            if (mp.find(key) != mp.end()) {
                return mp[key]; // Return precomputed result if found
            }
    
            long long taken = INT_MIN, skip = INT_MIN;
    
            // If it's the first element or it maintains the balanced condition
            if (prev == -1 || nums[idx] - idx >= nums[prev] - prev) {
                taken = nums[idx] + solve(idx, idx + 1, nums); // Take the current element
            }
    
            skip = solve(prev, idx + 1, nums); // Skip the current element
    
            // Store and return the max sum
            return mp[key] = max<long long>(taken, skip);
        }
    
        // Function to initiate the recursion
        long long maxBalancedSubsequenceSum(vector<int>& nums) {
            int maxEl = *max_element(begin(nums), end(nums)); // Find the max element in nums
            if (maxEl <= 0) return maxEl; // If all elements are non-positive, return the max element
            return solve(-1, 0, nums); // Start recursion with no previous element
        }
    };
    

//     # Leetcode Problem: Max Balanced Subsequence Sum (LC 2926)
// # Approach: Recursion + Memoization(Used unordered map due to very large constraints)

// # 1. We use recursion with memoization to solve the problem.
// # 2. Each subproblem is identified using a unique key (prev_index and current_index).
// # 3. The base case returns 0 when the index goes out of bounds.
// # 4. At each step, we either:
// #    - Take the current element if it satisfies the balanced condition.
// #    - Skip the current element and move to the next.
// # 5. The result is stored in a map to avoid redundant calculations.
// # 6. The final answer is obtained by calling solve(-1, 0, nums).
// # 7. If all elements are non-positive, return the max element.

// # Time Complexity: O(N^2) (worst case, due to checking all possibilities)
// # Space Complexity: O(N^2) (due to memoization storing all subproblems)
