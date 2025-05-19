#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            map<int, int> mp; // Stores value → index mapping
    
            for(int i = 0; i < n; i++) {
                int rem = target - nums[i]; // Compute the required pair value
    
                // If the required pair exists in map, return both indices
                if(mp.find(rem) != mp.end()) 
                    return {mp[rem], i};
    
                // Store current value and its index
                mp[nums[i]] = i;
            }
    
            return {}; // In case no pair found
        }
    };
    // # 🔢 Leetcode 1 – Two Sum (Optimized)

    // # ✅ Approach:
    // # For each element:
    // #   → Compute (target - current)
    // #   → If it exists in map → return [index_of_that, current_index]
    // #   → Else store current in map
    
    // # 🧠 Logic:
    // # HashMap stores value → index
    // # Check complement in O(1) time per element
    
    // # 🕒 Time Complexity: O(n)
    // # One pass through the array
    
    // # 💾 Space Complexity: O(n)
    // # Stores up to n elements in map
    
    // # 📦 Input Example:
    // # nums = [2, 7, 11, 15], target = 9
    // # map = {2:0}
    // # i = 1 → target - 7 = 2 → found in map → return [0,1]
    