#include <bits/stdc++.h>
using namespace std;

// Memoization TC = O(N*W) SC = O(N*W) + O(N)
class Solution {
  public:
    int t[1001][1001];
    int solve(vector<int>& val, vector<int>& wt, int idx, int W){
        if(idx == 0) return (W/wt[0]) * val[0];
        if(t[idx][W] != -1) return t[idx][W];
        int notTake = solve(val, wt, idx-1, W);
        int take = 0;
        if(W >= wt[idx]) take = val[idx] + solve(val, wt, idx, W-wt[idx]);
        
        return t[idx][W] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        memset(t, -1, sizeof(t));
        return solve(val, wt, n-1, capacity);
    }
};

// Tabulation TC = O(N*W) SC = O(N*W)
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        for(int w = 0; w<=capacity; w++){
            dp[0][w] = (w/wt[0]) * val[0];
        }
        for(int i=1; i<n; i++){
            for(int w = 0; w<= capacity; w++){
                int notTake = dp[i-1][w];
                int take = 0;
                if(w >= wt[i]) take = val[i] + dp[i][w-wt[i]];
                
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n-1][capacity];
    }
};