#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int i = 0;                  // Start pointer
            int j = nums.size() - 1;    // End pointer
    
            while(i < j) {
                int sum = nums[i] + nums[j];
    
                if(sum > target) j--;              // Too big → move end pointer left
                else if(sum < target) i++;         // Too small → move start pointer right
                else return {i + 1, j + 1};        // Found → return 1-based indices
            }
    
            return {}; // If no solution found
        }
    };
    // # 📘 Leetcode 167 – Two Sum II (Input Array Is Sorted)

    // # ✅ Approach:
    // # → Use two pointers from both ends of sorted array
    // # → If sum > target → move right pointer left
    // # → If sum < target → move left pointer right
    // # → Else return 1-based indices
    
    // # 🕒 Time Complexity: O(n)
    // # 💾 Space Complexity: O(1)
    
    // # 🧪 Example:
    // # nums = [2, 7, 11, 15], target = 9
    // # → 2 + 7 = 9 → return [1, 2]
        