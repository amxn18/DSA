#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int m = text1.length();
            int n = text2.length();
    
            // Initialize DP table with size (m+1) x (n+1) to handle base cases
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
            // Build the DP table bottom-up
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    // If characters match, extend the LCS by 1
                    if (text1[i - 1] == text2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } 
                    // Else, take the max by skipping one character from either string
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            // Final answer is in the bottom-right cell
            return dp[m][n];
        }
    };
    // # Leetcode 1143 - Longest Common Subsequence

    // # Approach: Bottom-Up Dynamic Programming (Tabulation)
    // #   - dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]
    // #   - If characters match: dp[i][j] = 1 + dp[i-1][j-1]
    // #   - Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    // #   - Initialize first row and column with 0 (base case)
    // #   - Final answer at dp[m][n]
    
    // # Time Complexity: O(m * n)
    // #   - m = length of text1
    // #   - n = length of text2
    
    // # Space Complexity: O(m * n)
    // #   - 2D DP table of size (m+1) x (n+1)
    
    // # Optimization Tip:
    // #   - Can be further space optimized to O(n) using two 1D arrays
        