#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;  // Store the size of the input array
        unordered_set<int> st;  // Hash set to track used elements
        vector<vector<int>> result;  // Stores all valid permutations
    
        // Backtracking function to generate all permutations
        void solve(vector<int>& temp, vector<int>& nums) {
            // Base Case: If 'temp' contains 'n' elements, it's a valid permutation
            if (temp.size() == n) {
                result.push_back(temp);
                return;
            }
    
            // Iterate over all elements in 'nums'
            for (int i = 0; i < n; i++) {
                // If nums[i] is not already used, include it in the current permutation
                if (st.find(nums[i]) == st.end()) {
                    temp.push_back(nums[i]);  // Add element to current permutation
                    st.insert(nums[i]);  // Mark element as used
                    
                    // Recursive call to build the next level of permutation
                    solve(temp, nums);
    
                    // Backtracking step
                    temp.pop_back();  // Remove last element to explore new possibilities
                    st.erase(nums[i]);  // Unmark element as used for future iterations
                }
            }
        }
    
        // Main function to generate all permutations
        vector<vector<int>> permute(vector<int>& nums) {
            n = nums.size();  // Store size of input array
            vector<int> temp;  // Temporary list to build permutations
            solve(temp, nums);  // Start backtracking
            return result;  // Return all generated permutations
        }
    };
    // backtracking approach used in the C++ code for Leetcode 46 (Permutations).
    
    // # Function to generate all possible permutations of a given array.
    // # Uses backtracking with an unordered_set to track used elements.
    
    // # 1. Base Condition: If the temporary list contains 'n' elements, store it in the result.
    // # 2. Loop through all elements of the input array.
    // # 3. If an element is not already used (not in the set), add it to the temporary list.
    // # 4. Recursively call the function to explore further permutations.
    // # 5. Backtrack by removing the last added element and erasing it from the set.
    
    // # Time Complexity: O(n!) (as we generate all possible orderings of 'n' elements).
        