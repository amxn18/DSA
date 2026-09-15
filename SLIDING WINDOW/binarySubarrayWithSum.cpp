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

// Prefix Sum + Hashmap 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum-goal;
            if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[sum]++;
        }
        return count;
    }
};

// Sliding Window + 2 Pointers
class Solution {
public:
    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum > k){
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};