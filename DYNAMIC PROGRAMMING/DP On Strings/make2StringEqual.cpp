#include <bits/stdc++.h>
using namespace std;


// LC 583
// Memoization 
class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(string& w1, string& w2, int i, int j){
        if(i >= m || j >= n) return 0;
        if(t[i][j] != -1) return t[i][j];

        if(w1[i] == w2[j]) return t[i][j] = 1 + solve(w1, w2, i+1, j+1);
        else return t[i][j] = max(solve(w1, w2, i+1, j), solve(w1, w2, i, j+1));
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        memset(t, -1, sizeof(t));
        int L = solve(word1, word2, 0, 0);
        return m + n - 2*L;
    }
};

// Bottom Up 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int L = dp[m][n];
        return m+n - 2*L;
    }
};