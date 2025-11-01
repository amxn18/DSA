#include <bits/stdc++.h>
using namespace std;

// LC 1248
// TC : O(2N)*2
// SC : O(1)
class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int l=0;
        int r=0;
        int sum = 0;
        int ctr = 0;
        if(k < 0) return 0;
        while(r<n){
            sum += nums[r]%2;
            while(sum > k){
                sum -= nums[l]%2;
                l++;
            }
            ctr = ctr + (r-l+1);
            r++;
        }
        return ctr;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
