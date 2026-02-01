#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            string text1 = s;
            string text2 = s;
    
            // Reverse the string to compare with original for palindromic subsequence
            reverse(begin(text2), end(text2));
    
            int m = text1.length();
            int n = text2.length();
    
            // Create a 2D DP table to store the lengths of LCS
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
            // Fill the table using bottom-up DP
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
    
                    // If characters match, extend the subsequence
                    if (text1[i - 1] == text2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } 
                    // If not, take the max by excluding one character at a time
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            // Final answer is in the bottom-right of the DP table
            return dp[m][n];
        }
    };

    // # Leetcode 516 - Longest Palindromic Subsequence

    // # 🧠 Intuition:
    // # A palindrome is the same when reversed. So, finding the Longest Palindromic Subsequence (LPS)
    // # is equivalent to finding the Longest Common Subsequence (LCS) between the original string `s`
    // # and its reversed version `rev_s`.
    
    // # 🧩 Approach:
    // # 1. Reverse the string and store in `text2`.
    // # 2. Compute the LCS between `text1` (original string) and `text2` using bottom-up DP.
    // # 3. If characters match, take 1 + diag value from DP.
    // # 4. If not, take max from left or top cell.
    // # 5. Return dp[m][n] which stores the length of LPS.
    
    // # ⏱️ Time Complexity: O(n^2)
    // # Because we fill an m x n DP table where n = s.length()
    
    // # 🗃️ Space Complexity: O(n^2)
    // # DP table of size (n+1) x (n+1) is used.
    
    // # ✅ Final Output:
    // # Length of the longest palindromic subsequence in the given string.
    