#include <bits/stdc++.h>
using namespace std;

// LC 1312
// Method 1: Recursion + Memoization
class Solution {
public:
    int t[501][501];
    int solve(string& s, int i, int j){
        if(i>=j) return 0;
        if(t[i][j] !=-1) return t[i][j];
        if(s[i] == s[j]) return t[i][j] = solve(s, i+1, j-1);
        else return t[i][j] = 1 + min(solve(s, i+1, j), solve(s, i, j-1));
    }
    int minInsertions(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};

// Method 2: Tabulation
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++){
            dp[i][i] = 0;
        }
        for(int l=2; l<=n; l++){
            for(int i=0; i<n-l+1; i++){
                int j = i+l-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};