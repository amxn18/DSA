#include <bits/stdc++.h>
using namespace std;

// LC 525
// TC: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) sum -= 1;
            else if(nums[i] == 1) sum += 1;
            if(sum == 0) maxLen = max(maxLen, i+1);
            if(mp.find(sum) != mp.end()) maxLen = max(maxLen, i-mp[sum]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxLen;
    }
};