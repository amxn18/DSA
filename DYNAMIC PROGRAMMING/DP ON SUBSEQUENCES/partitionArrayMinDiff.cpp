#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum;
        
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i=1; i<n; i++){
            for(int k=1; k<=target; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(nums[i] <= k) take = dp[i-1][k - nums[i]];

                dp[i][k] = take || notTake;
            }
        }

        int mini = 1e9;
        for(int s1=0; s1<=totalSum/2; s1++){
            if(dp[n-1][s1] == true){
                int s2 = totalSum - s1;
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};