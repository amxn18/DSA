#include <bits/stdc++.h>
using namespace std;

// LC 1092 – Shortest Common Supersequence
// Using SCS Table: TC O(m*n) SC O(m*n)
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
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

        string scs = "";
        int i = m;
        int j = n;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){ // Move diagonally
                scs.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    scs.push_back(s1[i-1]); // Move upwards
                    i--;
                }
                else{
                    scs.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i > 0){
            scs.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            scs.push_back(s2[j-1]);
            j--;
        }
        reverse(begin(scs), end(scs));
        return scs;
    }
};

// Using LCS Table: TC O(m*n) SC O(m*n)
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];    
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = m, j = n;
        string scs = "";

        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                scs += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                scs += s1[i-1];
                i--;
            } else {
                scs += s2[j-1];
                j--;
            }
        }
        while(i > 0) {
            scs += s1[i-1];
            i--;
        }
        while(j > 0) {
            scs += s2[j-1];
            j--;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};