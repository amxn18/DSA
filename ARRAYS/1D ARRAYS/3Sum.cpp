#include <bits/stdc++.h>
using namespace std;

// LC 15: 3Sum TC O(n^2) SC O(1) (excluding output space)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // avoid duplicates;
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Avoid duplicates
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            } 
        }
        return result;
    }
};