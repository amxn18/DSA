#include <bits/stdc++.h>
using namespace std;

// LC 5: Longest Palindromic Substring
class Solution {
public:  

    bool solve(string& s, int i, int j){
        if(i>=j) return true;
        if(s[i]==s[j]) return solve(s, i+1, j-1);
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int sp = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s,i,j) == true){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};

class Solution {
public:  
    int dp[1001][1001];
    bool solve(string& s, int i, int j){
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = solve(s, i+1, j-1);
        return dp[i][j] =  0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        int maxlen = INT_MIN;
        int sp = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s,i,j) == true){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;     
        int idx = 0;        
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }


        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1; 

                if (s[i] == s[j]) {
                    if (l == 2) {
                        dp[i][j] = true;  
                    } else {
                        dp[i][j] = dp[i + 1][j - 1]; 
                    }

                    if (dp[i][j] && l > maxLen) {
                        maxLen = l;
                        idx = i;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return s.substr(idx, maxLen);
    }
};