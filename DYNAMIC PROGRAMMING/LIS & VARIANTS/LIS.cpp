#include <bits/stdc++.h>
using namespace std;

// LC 300 - Longest Increasing Subsequence
// Recursive + Memoization  TC O(N^2)  SC O(N^2)

class Solution {
public:
    int n;
    int t[2501][2501];

    int solve(int idx, int prev, vector<int>& nums){
        if(idx >= n) return 0;
        if(t[idx][prev + 1] != -1) return t[idx][prev + 1];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]) take = 1 + solve(idx + 1, idx, nums);

        int skip = solve(idx + 1, prev, nums);

        return t[idx][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, -1, nums);
    }
};

// Bottom-Up Tabulation  TC O(N^2)  SC O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLIS = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};
