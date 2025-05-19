#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string shortestCommonSupersequence(string s1, string s2) {
            int m = s1.length();
            int n = s2.length();
    
            // Step 1: Build LCS DP table (not length of SCS directly)
            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(s1[i-1] == s2[j-1]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
    
            // Step 2: Reconstruct SCS from LCS table
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
    
            // Append remaining characters from s1 or s2
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

//     # LC 1092. Shortest Common Supersequence (Hard)

// # ✅ Idea:
// # - Use LCS to avoid repeating common characters in both strings.
// # - First build LCS DP table (not SCS directly).
// # - Then construct the SCS using LCS path:
// #   - If chars match → include once and move diagonally.
// #   - If not → include from the direction that gave the longer LCS.

// # ✅ Time Complexity: O(m * n)
// # ✅ Space Complexity: O(m * n)

// # 🔁 Works for printing actual SCS string.

    