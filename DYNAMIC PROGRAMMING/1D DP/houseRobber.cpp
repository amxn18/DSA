#include <bits/stdc++.h>
using namespace std;

// LC: 198. House Robber
// Method 1 : Recursion TC: O(2^n) SC: O(n)
class Solution {
public:
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        int steal = nums[i] + solve(nums, i+2);
        int leave = solve(nums, i+1);
        return max(steal, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0);
    }
};


// Method 2 : DP + Memoization TC: O(n) SC: O(n)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i+2);
        int leave = solve(nums, i+1);
        return t[i] = max(steal, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};

// Method 3 : DP + Tabulation TC: O(n) SC: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1, 0);
        t[0] = 0;
        t[1] = nums[0];
        for(int i=2; i<=n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(steal, skip);
        }
        return t[n];
    }
};