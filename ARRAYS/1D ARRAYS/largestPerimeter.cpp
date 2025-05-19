#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int largestPerimeter(vector<int>& nums) {
            int n = nums.size();
    
            // Step 1: Sort the array in non-decreasing order
            sort(nums.begin(), nums.end());
    
            // Step 2: Traverse from the end and check for a valid triangle
            // Triangle condition: sum of two smaller sides > largest side
            for (int i = n - 3; i >= 0; i--) {
                if (nums[i] + nums[i + 1] > nums[i + 2]) {
                    // Valid triangle found, return the perimeter
                    return nums[i] + nums[i + 1] + nums[i + 2];
                }
            }
    
            // No valid triangle found
            return 0;
        }
    };

    //  LeetCode 976: Largest Perimeter Triangle

    //  Problem:
    // Given an array of integers `nums` representing side lengths, 
    // find the largest perimeter of a triangle that can be formed using any 3 sides.
    // Return 0 if no such triangle can be formed.
    
    //  Approach:
    // 1. Sort the array in non-decreasing order.
    // 2. Start from the largest possible triplet (`i = n - 3`) and move backward.
    // 3. For each triplet (nums[i], nums[i+1], nums[i+2]), check if it satisfies the triangle condition:
    //    - nums[i] + nums[i+1] > nums[i+2]
    // 4. If condition is met, return their sum as the perimeter.
    // 5. If no such triplet exists, return 0.
    
    //  Time Complexity: O(n log n)
    // - Due to sorting.
    
    //  Space Complexity: O(1)
    // - No extra space used.
    