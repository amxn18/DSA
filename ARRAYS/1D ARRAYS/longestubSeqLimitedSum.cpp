#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Binary search to find the number of elements whose cumulative sum is <= target
        int binarySearch(vector<int>& nums, int n, int target) {
            int left = 0, right = n - 1;
            int idx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                // If current prefix sum <= target, move right to find more
                if (nums[mid] <= target) {
                    idx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return idx + 1; // +1 because idx is 0-based, and we want count
        }
    
        vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
            int n = nums.size();
            
            // Step 1: Sort the array to access smallest elements first
            sort(nums.begin(), nums.end());
    
            // Step 2: Convert to prefix sum array
            for (int i = 1; i < n; ++i) {
                nums[i] += nums[i - 1];
            }
    
            vector<int> result;
    
            // Step 3: For each query, binary search in prefix sum array
            for (int q : queries) {
                int count = binarySearch(nums, n, q);
                result.push_back(count);
            }
    
            return result;
        }
    };
    // # LeetCode 2389 - Longest Subsequence With Limited Sum

    // ## Problem:
    // Given an array of integers `nums` and an array `queries`, return an array where each element is the maximum length of a subsequence of `nums` such that the sum of its elements is less than or equal to the corresponding query value.
    
    // ## Approach:
    // 1. Sort the array `nums` to access smallest elements first. 
    // 2. Create a prefix sum array to allow sum calculation in O(1).
    // 3. For each query, perform binary search on the prefix sum to find the maximum count of elements whose sum is <= query.
    // 4. Store the count as result.
    
    // ## Code Explanation:
    // - Sort `nums`.
    // - Convert `nums` to prefix sum.
    // - For each query, use binary search to find max index `i` where `prefix[i] <= query`.
    // - Answer for that query is `i+1`.
    
    // ## Time Complexity:
    // - Sorting: O(n log n)
    // - Prefix sum: O(n)
    // - Each query (binary search): O(log n)
    // - Total: O(n log n + m log n)
    
    // ## Space Complexity:
    // - O(1) extra (in-place prefix sum)
    // - O(m) for result
    
    // # Clean and optimal.
        