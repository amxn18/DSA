#include <bits/stdc++.h>
using namespace std;

// LC 930
// Method 1: Using HashMap --> TC ~O(N) SC ~O(N)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ctr = 0;
        int sum = 0;
        mp[0] = 1;
        for(int num : nums){
            sum += num;
            int rem = sum - goal;
            if(mp.find(rem) != mp.end()) ctr+= mp[rem];
            mp[sum] ++;
        }
        return ctr;
    }
};

// TC ~O(2N)*2 SC ~O(1)
class Solution {
public:
    int atmost(vector<int>& nums, int x){
        int n = nums.size();
        int l = 0;
        int r=0;
        int sum = 0;
        int ctr = 0;
        while(r<n){
            sum += nums[r];
            if(x < 0) return 0;
            while(sum > x){
                sum -= nums[l];
                l++;
            }
            ctr = ctr + (r-l+1);
            r++;
        }
        return ctr;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }

};