#include <bits/stdc++.h>
using namespace std;

// LC 516 - Longest Palindromic Subsequence
// Method 1: Memoization TC = O(m*n) SC = O(m*n) + O(m+n)

class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(string& s1, string& s2, int i, int j){
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
        else return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string s1 = s;
        string s2 = s;
        reverse(begin(s2), end(s2));
        m = s1.size();
        n = s2.size();
        return solve(s1, s2, 0, 0);
    }
};

// Method 2: Tabulation TC = O(m*n) SC = O(m*n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        string text2 = s;
        reverse(begin(text2), end(text2));
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }    
        return dp[m][n];
    }
};

// Method 3
class Solution {
public:
    int t[1001][1001];
    int solve(string& s, int i, int j){
        if(i > j) return 0;
        if(i==j) return 1;
        if(t[i][j] != -1) return t[i][j];
        if(s[i] == s[j]) return t[i][j] = 2 + solve(s, i+1, j-1);
        else return t[i][j] = max(solve(s, i+1, j), solve(s, i , j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;  // Length 1 is palindrome
        }
        for(int l=2; l<=n; l++){
            for(int i=0; i<n-l+1; i++){
                int j = i+l-1;

                if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};