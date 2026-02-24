#include <bits/stdc++.h>
using namespace std;

// LC 322 
// Memoization TC O(n*amount) SC O(n*amount) + O(amount) for recursion stack
class Solution {
public:
    int t[1001][10001];
    int solve(vector<int>& coins, int idx, int amount){
        if(idx == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }

        if(t[idx][amount] != -1) return t[idx][amount];
        int notTake = solve(coins, idx-1, amount);
        int take = 1e9;
        if(amount >= coins[idx]) take = 1 + solve(coins, idx, amount-coins[idx]);

        return t[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int n = coins.size();
        int ans = solve(coins, n-1, amount);

        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Tabulation TC O(n*amount) SC O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int amt=0; amt<= amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = amt/coins[0];
            else dp[0][amt] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int amt = 0; amt <= amount; amt++){
                int notTake = dp[i-1][amt];
                int take = 1e9;
                if(amt >= coins[i]) take = 1 + dp[i][amt - coins[i]];

                dp[i][amt] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
