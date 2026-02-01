#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            // Every single character is a palindrome of length 1
            for(int i = 0; i < n; i++){
                dp[i][i] = 1;
            }
    
            // Fill DP table for substrings of length >= 2
            for(int l = 2; l <= n; l++) {
                for(int i = 0; i <= n - l; i++) {
                    int j = i + l - 1;
    
                    if(s[i] == s[j]) {
                        if(l == 2)
                            dp[i][j] = 2;  // Two equal chars side by side
                        else
                            dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
    
            return dp[0][n-1];
        }
    };
    // # Leetcode 516 - Longest Palindromic Subsequence

    // # 🧠 Intuition:
    // # To find the longest palindromic subsequence, we compare characters from both ends.
    // # If characters match, add 2 + LPS of the inner substring.
    // # If they don't, take the max of excluding either character.
    
    // # 🧩 Approach (Bottom-Up Tabulation):
    // # 1. Initialize dp[i][i] = 1 for all i (single character palindromes).
    // # 2. Fill the DP table diagonally for increasing substring lengths.
    // # 3. If s[i] == s[j], set dp[i][j] = 2 + dp[i+1][j-1].
    // # 4. Else, set dp[i][j] = max(dp[i+1][j], dp[i][j-1]).
    
    // # ⏱️ Time Complexity: O(n^2)
    // # We compute the LPS for all substrings of s.
    
    // # 🗃️ Space Complexity: O(n^2)
    // # A 2D DP array is used to store results for all i to j substrings.
    
    // # ✅ Final Output:
    // # dp[0][n-1] contains the length of the longest palindromic subsequence.
    
    