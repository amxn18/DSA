#include <bits/stdc++.h>
using namespace std;

// LC 992
// Optimized approach using sliding window and hash map TC: O(N) SC: O(256)
class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int maxLen = 0;
        int l = 0;
        int ctr = 0;
        unordered_map<int, int> mp;
        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ctr = ctr + (r-l+1);
        }
        return ctr;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};