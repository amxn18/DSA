#include <bits/stdc++.h>
using namespace std;

// LC 16: 3Sum Closest TC O(n^2) SC O(1)
class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int n = nums.size();
            int closestSum = 1e5; 
            sort(nums.begin(), nums.end());
    
            for (int k = 0; k <= n - 3; k++) {
                int i = k + 1;
                int j = n - 1;

                while (i < j) {
                    int currentSum = nums[k] + nums[i] + nums[j];

                    if (abs(target - currentSum) < abs(target - closestSum))  closestSum = currentSum;
                    if (currentSum < target) i++;
                    else j--;
                }
            }
    
            return closestSum;
        }
    };

        