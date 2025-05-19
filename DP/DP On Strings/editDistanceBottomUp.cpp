#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.length();
            int n = word2.length();
    
            // dp[i][j] = min edit distance to convert word1[0..i-1] → word2[0..j-1]
            vector<vector<int>> dp(m+1, vector<int>(n+1));
    
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i == 0 || j == 0)
                        dp[i][j] = i + j;  // Insert all or delete all
                    else if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];  // No op needed
                    else
                        dp[i][j] = 1 + min({dp[i][j-1],    // Insert
                                            dp[i-1][j],    // Delete
                                            dp[i-1][j-1]   // Replace
                                          });
                }
            }
    
            return dp[m][n];
        }
    };
    
    // # 🔍 Problem: Leetcode 72 – Edit Distance

    // # 🎯 Goal:
    // #   Convert word1 → word2 with min ops (Insert/Delete/Replace)
    
    // # 🧠 Approach:
    // #   - Tabulated DP
    // #   - dp[i][j] = min ops for word1[0..i-1] → word2[0..j-1]
    
    // # 🧱 Base Case:
    // #   - i==0 → Insert all chars of word2
    // #   - j==0 → Delete all chars of word1
    
    // # 🔁 Transition:
    // #   - If match:     dp[i][j] = dp[i-1][j-1]
    // #   - Else:         dp[i][j] = 1 + min(insert, delete, replace)
    
    // # 🕒 Time: O(m * n)
    // # 🗂️ Space: O(m * n)
            