#include <bits/stdc++.h>
using namespace std;

// LC 518
// Method 1: Recursion + Memoization TC O(N*amount) SC O(N*amount) + O(N) for recursion stack
class Solution {
public:
    int t[301][5001];
    int solve(vector<int>& coins, int amount, int idx){
        if(idx == 0){
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(t[idx][amount] != -1) return t[idx][amount];
        int notTake = solve(coins, amount, idx-1);
        int take = 0;
        if(amount >= coins[idx]) take = solve(coins, amount - coins[idx], idx);

        return t[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(coins, amount, n-1);
    }
};
