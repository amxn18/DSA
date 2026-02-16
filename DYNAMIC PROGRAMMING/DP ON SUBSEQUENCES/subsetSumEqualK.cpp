#include <bits/stdc++.h>
using namespace std;

// Memoization TC = O(n*k) SC = O(n*k) for recursion stack
class Solution {
  public:
    int t[201][10001];
    bool solve(int idx, int k, vector<int>& arr){
        if(k == 0) return true;
        if(idx < 0) return false;
        if(t[idx][k] != -1) return t[idx][k];
        
        bool notTake = solve(idx-1, k, arr);
        bool take = false;
        if(k >= arr[idx]) take = solve(idx-1, k-arr[idx], arr);
        
        return t[idx][k] = take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(n-1, sum, arr);
    }
};

// Tabulation TC = O(n*k) SC = O(n*k)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = false; 
        }
        dp[0][arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int k=1; k<=sum; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(k >= arr[i]) take = dp[i-1][k-arr[i]];
                
                dp[i][k] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};