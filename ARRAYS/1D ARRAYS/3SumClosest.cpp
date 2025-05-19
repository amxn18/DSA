#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int n = nums.size();
            int closestSum = 1e5; // Initialize with a large value
    
            // Sort the array to use two-pointer approach
            sort(nums.begin(), nums.end());
    
            for (int k = 0; k <= n - 3; k++) {
                int i = k + 1;
                int j = n - 1;
    
                // Two-pointer approach to find the closest sum with nums[k]
                while (i < j) {
                    int currentSum = nums[k] + nums[i] + nums[j];
    
                    // Update closestSum if current is closer to target
                    if (abs(target - currentSum) < abs(target - closestSum)) {
                        closestSum = currentSum;
                    }
    
                    // Move pointers based on how currentSum compares to target
                    if (currentSum < target) {
                        i++;
                    } else {
                        j--;
                    }
                }
            }
    
            return closestSum;
        }
    };
    // LeetCode 16: 3Sum Closest

    //  Problem:
    // Given an array `nums` and a target integer, return the sum of three integers 
    // in `nums` such that the sum is closest to the target.
    
    //  Approach:
    // 1. Sort the array.
    // 2. Fix one number using index `k` in a loop.
    // 3. Use two pointers `i = k + 1` and `j = n - 1` to find two other numbers.
    // 4. Calculate the sum: nums[k] + nums[i] + nums[j].
    // 5. If this sum is closer to the target than the current best, update the result.
    // 6. Move pointers:
    //    - If sum < target → i++
    //    - If sum > target → j--
    // 7. Repeat the process and return the closest sum.
    
    //  Time Complexity: O(n^2)
    // - Sorting takes O(n log n)
    // - Outer loop runs O(n)
    // - Inner two-pointer loop runs O(n) for each k
    
    //  Space Complexity: O(1)
    // - No extra space used apart from sorting in-place
        