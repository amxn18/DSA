#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n == 0) return 0;
    
            int left = 0, right = n - 1;
            int leftMax = 0, rightMax = 0;
            int water = 0;
    
            while (left < right) {
                if (height[left] < height[right]) {
                    // Left is the limiting factor
                    if (height[left] >= leftMax)
                        leftMax = height[left];
                    else
                        water += leftMax - height[left];
                    left++;
                } else {
                    // Right is the limiting factor
                    if (height[right] >= rightMax)
                        rightMax = height[right];
                    else
                        water += rightMax - height[right];
                    right--;
                }
            }
    
            return water;
        }
    };
    // # Problem: Trapping Rain Water (Leetcode 42) 

    // #  Goal:
    // # Given elevation map (heights), find total water trapped between bars after raining.
    
    // #  Intuition:
    // # Water trapped at any point is min(left_max, right_max) - height[i]
    // # Instead of precomputing arrays, use two pointers (left, right) and track leftMax/rightMax while moving inward.
    
    // #  Approach:
    // # 1. Initialize left = 0, right = n-1
    // # 2. leftMax = 0, rightMax = 0 to track max heights from both ends
    // # 3. While left < right:
    // #    - If height[left] < height[right], process left side:
    // #        - If current height >= leftMax → update leftMax
    // #        - Else → water += leftMax - height[left]
    // #        - Move left++
    // #    - Else process right side similarly
    // # 4. Keep adding trapped water as we go
    
    // #  Time Complexity:
    // # O(n) → Single pass with two pointers
    
    // #  Space Complexity:
    // # O(1) → Constant space (no extra arrays or stacks)
    
    // #  Handles:
    // # - Efficient memory usage
    // # - No stack used
    // # - Works well for large input
        
