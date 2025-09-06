#include <bits/stdc++.h>
using namespace std;

// LC 90. Subsets II
// TC --> O(2^n * n) SC --> O(2^n * k) + O(n) k is the average length of each subset
class Solution {
public:  
    vector<vector<int>> result;
    void f(int idx, vector<int>& nums, vector<int>& temp){
        result.push_back(temp);
        for(int i = idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            f(i+1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(0, nums, temp);
        return result;
    }
};