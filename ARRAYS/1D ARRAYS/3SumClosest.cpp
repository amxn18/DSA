#include <bits/stdc++.h>
using namespace std;

// LC 16: 3Sum Closest TC O(n^2) SC O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 1e5;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(closestSum - target)) closestSum = sum;
                if(sum < target) j++;
                else k--;
            }
        }
        return closestSum;
    }
};
        