#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int t[201][1001]; // DP table to store intermediate results
    
        // Recursive function to count the number of possible combinations
        int solve(int idx, vector<int>& nums, int target) {
            // Base case: If target becomes 0, we found a valid combination
            if(target == 0) return 1;
            // If index goes out of bounds or target becomes negative, return 0
            if(idx >= n || target < 0) return 0;
            // If the result is already computed, return from DP table
            if(t[idx][target] != -1) return t[idx][target];
    
            int result = 0;
            // Iterate through all elements to form different combinations
            for(int i = idx; i < n; i++) {
                int takeIdx = solve(0, nums, target - nums[i]); // Start again from index 0 for permutations
                result += takeIdx;
            }
            // Store the computed result
            return t[idx][target] = result;
        }
    
        int combinationSum4(vector<int>& nums, int target) {
            n = nums.size();
            memset(t, -1, sizeof(t)); // Initialize DP table with -1
            return solve(0, nums, target); // Start recursion from index 0
        }
    };
    // # Define a class Solution with two main functions: solve() and combinationSum4() LC 377
    // # We use recursion with memoization to count all unique permutations to reach the target sum.
    
    // # Base Cases:
    // # 1. If target == 0 → Found a valid combination, return 1
    // # 2. If target < 0 or index exceeds the array size → Invalid case, return 0
    
    // # Recursive Logic:
    // # - We iterate through the nums array to explore all elements.
    // # - Each time we subtract the chosen number from the target and recursively call solve(0, nums, new_target).
    // # - Unlike subsets, we restart from index 0 after every pick to allow permutations.
    
    // # Memoization:
    // # - We use a 2D DP array (t[idx][target]) to store already computed results.
    
    // # Time Complexity: O(n * target)
    // # Space Complexity: O(n * target) due to memoization table.
    