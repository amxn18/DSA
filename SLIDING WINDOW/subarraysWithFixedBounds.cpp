#include <bits/stdc++.h>
using namespace std;

// LC 2444. Count Subarrays With Fixed Bounds
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minKIdx = -1;
        int maxKIdx = -1;
        int culpritIdx = -1;

        long long ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > maxK || nums[i] < minK) culpritIdx = i;
            if(nums[i] == minK) minKIdx = i;
            if(nums[i] == maxK) maxKIdx = i;

            long long smallerIdx = min(minKIdx, maxKIdx);
            long long temp = smallerIdx - culpritIdx;
            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};