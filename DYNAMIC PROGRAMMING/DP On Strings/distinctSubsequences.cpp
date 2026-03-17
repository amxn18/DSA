#include <bits/stdc++.h>
using namespace std;

// LC 115. Distinct Subsequences
// Recursive + Memoization TC: O(N*M) SC: O(N*M) + O(N+M)
class Solution {
public:
    long long dp[1001][1001];
    long long solve(string& s1, string& s2, int i, int j){
        if(j < 0) return 1;   // matched whole s2
        if(i < 0) return 0;   // s1 exhausted

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i-1, j-1) + solve(s1, s2, i-1, j);
        else return dp[i][j] = solve(s1, s2, i-1, j);
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, m-1, n-1);
    }
};

// Tabulation TC: O(N*M) SC: O(N*M)
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m+1, vector<long long>(n+1));

        for(int i=0; i<=m; i++) dp[i][0] = 1;
        for(int j=1; j<=n; j++) dp[0][j] = 0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m][n]; 
    }
};
