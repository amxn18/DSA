#include <bits/stdc++.h>
using namespace std;

// LC 188 
// Recursion + Memoization TC O(N*2*K) SC O(N*2*K) + O(N)
class Solution {
public:
    int n;
    long long t[1001][2][101];
    long long solve(int idx, int buy, int k, vector<int>& prices){
        if(k == 0) return 0;
        if(idx == n) return 0;
        if(t[idx][buy][k] != -1) return t[idx][buy][k];

        long long profit = 0;
        if(buy) profit = max((-prices[idx] + solve(idx+1, 0, k, prices)), (0 + solve(idx+1, 1, k, prices)));
        else profit = max((prices[idx] + solve(idx+1, 1, k-1, prices)), (0 + solve(idx+1, 0, k, prices)));

        return t[idx][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        long long ans = solve(0, 1, k, prices);
        return (int)(ans);
    }
};

// Tabulation TC O(N*2*K) SC O(N*2*K)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2, vector<long long>(k+1, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int txn = 1; txn <= k; txn++){
                    if(buy == 1) dp[i][buy][txn] = max(-prices[i] + dp[i+1][0][txn], 0 + dp[i+1][1][txn]);
                    else dp[i][buy][txn] = max(prices[i] + dp[i+1][1][txn-1], 0 + dp[i+1][0][txn]);
                }
            }
        }

        return dp[0][1][k];
    }
};