#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int l = flowerbed.size();
    
            // If no flowers need to be planted, return true
            if (n == 0) return true;
    
            // Iterate through the flowerbed
            for (int i = 0; i < l; i++) {
                // Check if current plot is empty
                if (flowerbed[i] == 0) {
                    // Check if left and right plots are empty or out of bounds
                    bool left = (i == 0) || (flowerbed[i - 1] == 0);
                    bool right = (i == l - 1) || (flowerbed[i + 1] == 0);
    
                    // Plant a flower if both sides are empty
                    if (left && right) {
                        flowerbed[i] = 1;  // Mark as planted
                        n--;               // Decrease required count
    
                        // If no more flowers to plant, return true
                        if (n == 0) return true;
                    }
                }
            }
    
            // Return false if unable to plant all flowers
            return false;
        }
    };
    // LeetCode 605: Can Place Flowers

    // Problem:
    // You are given a flowerbed (array of 0s and 1s) and an integer n. 
    // 0 means empty and 1 means a flower is planted.
    // Determine if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
    
    // Approach:
    // 1. Traverse the flowerbed array.
    // 2. For each empty plot (0), check if both adjacent plots (left and right) are also empty or out of bounds.
    // 3. If so, plant a flower (set to 1) and decrement n.
    // 4. If at any point n becomes 0, return true.
    // 5. If the loop ends and n > 0, return false.
    
    // Time Complexity: O(n)
    // - Each plot is visited once.
    
    // Space Complexity: O(1)
    // - Constant extra space used.
        