#include <bits/stdc++.h>
using namespace std;

// LC 123
// Recursion + Memoization TC O(N*2*3) SC O(N*2*3) + O(N)
class Solution {
public:
    int n;
    long long t[100001][2][3];
    long long solve(int idx, int buy, int txnCompleted, vector<int>& prices){
        if(txnCompleted == 0) return 0;
        if(idx == n) return 0;
        if(t[idx][buy][txnCompleted] != -1) return t[idx][buy][txnCompleted];

        long long profit = 0;
        if(buy) profit = max((-prices[idx] + solve(idx+1, 0, txnCompleted, prices)), (0 + solve(idx+1, 1, txnCompleted, prices)));
        else profit = max((prices[idx] + solve(idx+1, 1, txnCompleted-1, prices)), (0 + solve(idx+1, 0, txnCompleted, prices)));

        return t[idx][buy][txnCompleted] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        long long ans = solve(0, 1, 2, prices);
        return (int)(ans);
    }
};

// Tabulation TC O(N*2*3) SC O(N*2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (2, vector<long long> (3, 0)));
        
        long long profit = 0;
        for(int i=n-1; i>= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int txn = 1; txn <= 2; txn++){
                    if(buy == 1) profit = max((-prices[i] + dp[i+1][0][txn]), (0 + dp[i+1][1][txn]));
                    else profit = max((prices[i] + dp[i+1][1][txn-1]), (0 + dp[i+1][0][txn]));

                    dp[i][buy][txn] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};