#include <bits/stdc++.h>
using namespace std;

// Importent Pattern
// Method 1 Using Recursion
// TC -> O((2^n)*n)
// SC -> O(n) + O(n)  (Auxiliary Stack Space + Temporary Array)
class Solution {
public:
    vector<vector<int>> result;
    void f(int idx, vector<int>& nums, vector<int>& temp){
        int n = nums.size();
        if(idx >= n){   // Base Case
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1, nums, temp); //Take
        temp.pop_back();
        f(idx+1, nums, temp); // Not Take
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        f(0, nums, temp);
        return result;
    }
};

// Method 2 Using Bit Manipulation
// TC -> O((2^n)*n)
// SC O(1) --> O(n) (Temporary Array)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int num = 0; num < (1 << n); num++){
            vector<int> temp;
            for(int i = 0; i < n; i++){
                if(num & (1 << i)) temp.push_back(nums[i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
