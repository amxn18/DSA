#include <bits/stdc++.h>
using namespace std;

// LC 416. Partition Equal Subset Sum
// Memoization TC = O(n*target) SC = O(n*target) for recursion stack
class Solution {
public:
    int t[201][10001];
    bool solve(vector<int>& nums, int idx, int target){
        if(target == 0) return true;
        if(idx < 0) return false;
        if(t[idx][target] != -1) return t[idx][target];
        bool notTake = solve(nums, idx-1, target);
        bool take = false;
        if(target >= nums[idx]) take = solve(nums, idx-1, target-nums[idx]);
        return t[idx][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x: nums) sum+=x;
        if(sum % 2 != 0) return false;
        int target = sum/2;
        memset(t, -1, sizeof(t));
        return solve(nums, n-1, target);
    }
};

// Tabulation TC = O(n*target) SC = O(n*target)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 != 0) return false;

        int target = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i=0; i<n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;


        for(int i=1; i<n; i++){
            for(int k = 1; k<=target; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(k >= nums[i]) take = dp[i-1][k - nums[i]];
                dp[i][k] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};