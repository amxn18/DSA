#include <bits/stdc++.h>
using namespace std;

// LC 494
// Method 1: Recursion  TC O(2^N) SC O(N) for recursion stack
class Solution {
public:
    int n;
    int solve(vector<int>& nums, int target, int idx, int sum){
        if(idx == n){
            if(sum == target) return 1;
            else return 0;
        }

        int plus = solve(nums, target, idx+1, sum + nums[idx]);
        int minus = solve(nums, target, idx+1, sum - nums[idx]);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return solve(nums, target, 0, 0);
    }
};
// Memoization + Recursion TC O(N*sum) SC O(N*sum) + O(N) for recursion stack
class Solution {
public:
    int t[21][40001];
    int n;
    int solve(vector<int>& nums, int target, int idx, int sum){
        if(idx == n){
            if(sum == target) return 1;
            else return 0;
        }
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(t[idx][sum + S] != -1) return t[idx][sum + S];
        int plus = solve(nums, target, idx+1, sum + nums[idx]);
        int minus = solve(nums, target, idx+1, sum - nums[idx]);

        return t[idx][sum + S] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target, 0, 0);
    }
};

