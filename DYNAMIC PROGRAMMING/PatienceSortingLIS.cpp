#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> sorted;  // Stores the increasing subsequence
            for(int i = 0; i < n; i++) {
                auto it = lower_bound(begin(sorted), end(sorted), nums[i]);  
                if(it == end(sorted)){
                    sorted.push_back(nums[i]);   // If nums[i] is the largest element, append it
                } else {
                    *it = nums[i]; // Replace the element to maintain the lowest possible values
                }
            }
            return sorted.size();
        }
    };

    // # Leetcode Problem: Longest Increasing Subsequence (LIS)
    // # Approach: Patience Sorting with Binary Search (Greedy + Binary Search)
    
    // # 1. We maintain a vector 'sorted' to store the smallest possible increasing subsequence.
    // # 2. For each element in nums:
    // #    - Find its position in 'sorted' using lower_bound.
    // #    - If it is greater than all elements, append it.
    // #    - Otherwise, replace the found element to keep LIS minimal.
    // # 3. The length of 'sorted' at the end gives the LIS.
    
    // # Time Complexity: O(N log N) (Binary search in a sorted list for each element)
    // # Space Complexity: O(N) (Storing the LIS sequence)
    