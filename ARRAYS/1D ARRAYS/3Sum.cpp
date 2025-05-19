#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;  // Stores unique triplets
            int n = nums.size();
            if (n < 3) return result;    // Not enough elements
    
            sort(nums.begin(), nums.end()); // Step 1: Sort the array
    
            for (int i = 0; i < n - 2; ++i) {
                // Skip duplicate elements to avoid duplicate triplets
                if (i > 0 && nums[i] == nums[i - 1]) continue;
    
                int target = -nums[i];         // We want nums[j] + nums[k] = -nums[i]
                int left = i + 1;
                int right = n - 1;
    
                // Two-pointer approach to find valid pairs
                while (left < right) {
                    int sum = nums[left] + nums[right];
    
                    if (sum < target) {
                        ++left;  // Move right for bigger sum
                    } else if (sum > target) {
                        --right; // Move left for smaller sum
                    } else {
                        // Valid triplet found
                        result.push_back({nums[i], nums[left], nums[right]});
    
                        // Skip duplicate values at left and right
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
    
                        // Move both pointers inward
                        ++left;
                        --right;
                    }
                }
            }
    
            return result;
        }
    };
    // # 🧠 Problem: 3Sum (Leetcode 15) 

    // # 🧩 Goal:
    // # Find all unique triplets (a, b, c) in the array where a + b + c = 0
    
    // # 🔍 Intuition:
    // # Use sorting + 2-pointer technique to reduce time complexity from O(n^3) to O(n^2)
    
    // # ⚙️ Approach:
    // # 1. Sort the array to simplify duplicate handling and allow 2-pointer logic.
    // # 2. Fix one number at a time (nums[i]) and use two pointers (j, k) to find the remaining two such that:
    // #       nums[i] + nums[j] + nums[k] == 0 → nums[j] + nums[k] == -nums[i]
    // # 3. Skip duplicates for the fixed number and also inside the 2-pointer loop to avoid repeated triplets.
    // # 4. Store valid triplets when sum matches, and move both pointers while skipping duplicate values.
    
    // # 🔁 Loop Flow:
    // # for each i from 0 to n-2:
    // #     skip nums[i] if it's same as previous (duplicate)
    // #     set left = i+1, right = n-1
    // #     while left < right:
    // #         sum = nums[left] + nums[right]
    // #         if sum == -nums[i], store triplet and move both pointers skipping duplicates
    // #         else if sum < -nums[i], move left
    // #         else move right
    
    // # 🕒 Time Complexity:
    // # O(n^2) → sorting takes O(n log n), and each i with 2-pointer takes O(n)
    
    // # 💾 Space Complexity:
    // # O(1) extra (excluding output) → sorting is in-place
    
    // # ✅ Handles:
    // # - Duplicates (both fixed and 2-pointer sides)
    // # - Negative and positive numbers
    // # - Efficient for large input due to two-pointer optimization
        