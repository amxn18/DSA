#include <bits/stdc++.h>
using namespace std;

// 309 
// Recursion + Memoization TC - O(N*2) SC - O(N*2) + O(N) for recursion stack
class Solution {
public:
    int n;
    long long t[5001][2];
    long long solve(int idx, int buy, vector<int>& prices){
        if(idx >= n) return 0;
        if(t[idx][buy] != -1) return t[idx][buy];

        long long profit = 0;
        if(buy) profit = max((-prices[idx] + solve(idx+1, 0, prices)), (0 + solve(idx+1, 1, prices)));
        else profit = max((prices[idx] + solve(idx+2, 1, prices)), (0 + solve(idx+1, 0, prices)));

        return t[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        long long result = solve(0, 1, prices);
        return (int)(result);
    }
};

// Tabulation TC - O(N*2) SC - O(N*2)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> dp(n+2, vector<long long>(2, 0));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 1) dp[i][buy] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
                else dp[i][buy] = max(prices[i] + dp[i+2][1],  0 + dp[i+1][0]);
            }
        }

        return dp[0][1];
    }
};