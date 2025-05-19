#include <bits/stdc++.h>
using namespace std;
class Solution {
    public: 
        int n;
        
        void bt(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
            if (curr.size() >= 2) {
                result.push_back(curr);
            }
    
            unordered_set<int> st; // To prevent duplicate elements at this recursion level
            
            for (int i = idx; i < n; i++) {
                // Ensure increasing order & avoid duplicates
                if ((curr.empty() || nums[i] >= curr.back()) && st.find(nums[i]) == st.end()) {
                    curr.push_back(nums[i]);   // Choose the element
                    bt(nums, i + 1, curr, result); // Move to the next index
                    curr.pop_back();           // Backtrack
    
                    st.insert(nums[i]); // Mark this element to prevent duplicate usage
                }
            }
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            n = nums.size();
            vector<vector<int>> result;
            vector<int> curr;
            bt(nums, 0, curr, result);
            return result;
        }
    };
    // # Problem: Given an array nums, find all possible increasing subsequences of length >= 2.

    // # Approach:
    // # 1. Use Backtracking to explore all possible subsequences.
    // # 2. Maintain a temporary vector `curr` to store the current subsequence.
    // # 3. Use a set `st` to avoid duplicate numbers at the same recursion level.
    // # 4. If `curr` has 2 or more elements, add it to the result.
    // # 5. Traverse the array, ensuring elements are non-decreasing.
    // # 6. If the current number hasn't been used at this level, add it to `curr`, recurse, then backtrack.
    // # 7. Time Complexity: O(2^N) in the worst case, but pruning optimizes it.
    
    // # Key Observations:
    // # - Use `st` to avoid duplicate elements at the same recursion level.
    // # - Backtracking ensures all valid subsequences are explored.
    // # - We pass `i+1` in recursion to ensure elements appear in order.
    
    // # Example:
    // # Input: [4,6,7,7]
    // # Output: [[4,6], [4,6,7], [4,6,7,7], [4,7], [4,7,7], [6,7], [6,7,7], [7,7]]
        
    