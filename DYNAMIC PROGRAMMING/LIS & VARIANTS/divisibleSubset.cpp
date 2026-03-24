#include <bits/stdc++.h>
using namespace std;

// LC 368 - Largest Divisible Subset
// Recursive Backtracking  TC O(2^N)  SC O(N) (Recursion depth)
class Solution {
public:
    void solve(int idx, int prev, vector<int>&nums, vector<int>& temp, vector<int>& result){
        if(idx >= nums.size()){
            if(temp.size() > result.size()) result = temp;
            return;
        }

        if(prev == -1 || nums[idx] % nums[prev] == 0){
            temp.push_back(nums[idx]);
            solve(idx+1, idx, nums, temp, result);
            temp.pop_back();
        }
        solve(idx+1, prev, nums, temp, result);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> result;

        solve(0, -1, nums, temp, result);
        return result;
    }
};

// Recusion + Reconstruction  TC O(N^2)  SC O(N^2)
class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int idx, int prev, vector<int>& nums) {
        if (idx >= n) return 0;

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int take = 0;

        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            take = 1 + solve(idx + 1, idx, nums);
        }

        int skip = solve(idx + 1, prev, nums);

        return dp[idx][prev + 1] = max(take, skip);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));

        int maxLen = solve(0, -1, nums);

        // Reconstruction
        vector<int> result;
        int idx = 0, prev = -1;

        while (idx < n) {
            if (prev == -1 || nums[idx] % nums[prev] == 0) {
                int take = 1 + solve(idx + 1, idx, nums);
                int skip = solve(idx + 1, prev, nums);

                if (take >= skip) {
                    result.push_back(nums[idx]);
                    prev = idx;
                }
            }
            idx++;
        }

        return result;
    }
};


// Bottom up 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> dp(n, 1);  
        vector<int> prev(n, -1); 

        int lastIdx = 0; 
        int maxEl = 1;    

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > maxEl){
                maxEl = dp[i];
                lastIdx = i;
            }
        }

        vector<int> result;
        while(lastIdx != -1){
            result.push_back(nums[lastIdx]);
            lastIdx = prev[lastIdx];
        }

        reverse(result.begin(), result.end()); 
        return result;
    }
};