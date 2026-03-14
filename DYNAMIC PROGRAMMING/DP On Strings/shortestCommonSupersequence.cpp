#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursion + Memoization
// TC: O(m*n) SC: O(m*n) + O(m+n) (for recursion stack)
class Solution {
  public:
    int t[501][501];
    int solve(string& s1, string& s2, int i, int j){
        if(i==0) return j;
        else if(j==0) return i;
        
        if(t[i][j] != -1) return t[i][j];
        
        if(s1[i-1] == s2[j-1]) return t[i][j] = 1 + solve(s1, s2, i-1, j-1);
        else return t[i][j] =  1 + min(solve(s1, s2, i-1, j), solve(s1, s2, i, j-1));
    }
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }
};

// Method 2: Tabulation
// TC: O(m*n) SC: O(m*n)
class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

// Method 3: Using LCS 
// TC: O(m*n) SC: O(m*n)
class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int L = dp[m][n];
        int a = m - L;
        int b = n - L;
        
        return a + b + L;
    }
};
