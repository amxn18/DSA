#include <bits/stdc++.h>
using namespace std;

// LC 448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp.find(i+1) == mp.end()) res.push_back(i+1);
        }
        return res;
    }
};

// M2
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)  res.push_back(i + 1);
        }

        return res;
    }
};