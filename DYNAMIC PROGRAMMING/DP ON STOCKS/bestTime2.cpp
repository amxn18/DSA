#include <bits/stdc++.h>
using namespace std;

// LC 122 
// Recursion + Memoization TC O(N*2) SC O(N*2) + O(N)
class Solution {
public:
    int n;
    long long t[30001][2];
    long long solve(int idx, int buy, vector<int>& prices){
        if(idx == n) return 0;
        if(t[idx][buy] != -1) return t[idx][buy];

        long long profit = 0;
        if(buy) profit = max((-prices[idx] + solve(idx+1, 0, prices)), (0 + solve(idx+1, 1, prices)));
        else profit = max((prices[idx] + solve(idx+1, 1, prices)), (0 + solve(idx+1, 0, prices)));

        return t[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        long long result = solve(0, 1, prices);
        return (int)(result);
    }
};

// Tabulation TC O(N*2) SC O(N*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        long long profit = 0;
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy==1) profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
                else profit = max((prices[i] + dp[i+1][1]), (0 + dp[i+1][0]));
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};