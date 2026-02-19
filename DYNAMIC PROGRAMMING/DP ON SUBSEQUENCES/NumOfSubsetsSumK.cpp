#include <bits/stdc++.h>
using namespace std;

// Memoization TC: O(N*K) SC: O(N*K) + O(N)
class Solution {
  public:
    int t[1001][1001];
    int solve(vector<int>& nums, int idx, int target){
        if(target == 0) return 1;
        if(idx < 0) return 0;
        if(t[idx][target] != -1) return t[idx][target];
        int notTake = solve(nums, idx-1, target);
        int take = 0;
        if(target >= nums[idx]) take = solve(nums, idx-1, target-nums[idx]);
        
        return t[idx][target] = take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, n-1, target);
    }
};


class Solution {
  public:
    int isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1; 
        }
        dp[0][arr[0]] = 1;
        for(int i=1; i<n; i++){
            for(int k=1; k<=sum; k++){
                int notTake = dp[i-1][k];
                int take = 0;
                if(k >= arr[i]) take = dp[i-1][k-arr[i]];
                
                dp[i][k] = take + notTake;
            }
        }
        return dp[n-1][sum];
    }
};