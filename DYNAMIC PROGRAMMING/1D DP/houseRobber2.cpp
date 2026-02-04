#include <bits/stdc++.h>
using namespace std;

// LC : 213. House Robber II
// Method 1 : DP + Tabulation TC: O(n) SC: O(n)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int end) {
        if (i > end) return 0;
        if (t[i] != -1) return t[i];
        int take = nums[i] + solve(nums, i + 2, end);
        int skip = solve(nums, i + 1, end);
        return t[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        memset(t, -1, sizeof(t));
        int firstHouse = solve(nums, 0, n - 2);
        memset(t, -1, sizeof(t));
        int lastHouse = solve(nums, 1, n - 1);
        return max(firstHouse, lastHouse);
    }
};

// Method 2 : DP + Tabulation TC: O(n) SC: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1, 0);
        // Case 1 Taking 1st house and skipping last
        dp[0] = 0;
        for(int i=1; i<=n-1; i++){
            int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }
        int result1 = dp[n-1];
        dp.clear();
        // Case 2 Skipping first house and taking last
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=n; i++){
            int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }
        int result2 = dp[n];
        return max(result1, result2);
    }
};