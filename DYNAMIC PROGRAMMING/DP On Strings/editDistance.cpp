#include <bits/stdc++.h>
using namespace std;

// LC 72 – Edit Distance
// recursive + memoization TC O(m*n) SC O(m*n)

class Solution {
    public:
        int m, n;
        int dp[501][501]; 
    
        int solve(string word1, string word2, int i, int j) {
            if(i == m) return n - j;
            if(j == n) return m - i;
    
            if(dp[i][j] != -1) return dp[i][j];
    
            if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i+1, j+1);
                
            int insert = 1 + solve(word1, word2, i, j+1);
            int del = 1 + solve(word1, word2, i+1, j);
            int replace = 1 + solve(word1, word2, i+1, j+1);
    
            return dp[i][j] = min({insert, del, replace});
        }
    
        // Main function
        int minDistance(string word1, string word2) {
            m = word1.length();
            n = word2.length();
            memset(dp, -1, sizeof(dp)); 
            return solve(word1, word2, 0, 0);
        }
};

// Bottom-up DP TC O(m*n) SC O(m*n)
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.length();
            int n = word2.length();
    
            vector<vector<int>> dp(m+1, vector<int>(n+1));
    
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i == 0 || j == 0) dp[i][j] = i + j; 
                    else if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];  
                    else dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                        
                }
            }
            return dp[m][n];
        }
    };
    