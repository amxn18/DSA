#include <bits/stdc++.h>
using namespace std;
// LC 330 TC --> O(max(l, log n)) l--> length of nums
class Solution {
    public:
        int minPatches(vector<int>& nums, int n) {
            int patch = 0;  // Count of numbers we need to patch
            long maxReach = 0;  // Maximum sum we can form so far
            int i = 0;  // Pointer for nums array
            
            // Continue until we can represent all numbers from 1 to n
            while (maxReach < n) {
                if (i < nums.size() && nums[i] <= maxReach + 1) {
                    // If nums[i] extends our range, add it to maxReach
                    maxReach += nums[i];
                    i++;
                } else {
                    // Otherwise, patch by adding (maxReach + 1)
                    maxReach += (maxReach + 1);
                    patch++;
                }
            }
            return patch;
        }
    };
    