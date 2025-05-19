#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int m, n;
        int dp[1001][1001];  // DP array to memoize LCS results
    
        // Recursive function to find LCS between text1 and text2
        int solve(string& text1, string& text2, int i, int j) {
            if (i >= m || j >= n) return 0;  // Base case: reached end of either string
    
            if (dp[i][j] != -1) return dp[i][j];  // If already computed, return it
    
            if (text1[i] == text2[j]) {
                // Characters match → include it and move diagonally
                return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1);
            } else {
                // Characters don't match → explore both possibilities and take max
                return dp[i][j] = max(
                    solve(text1, text2, i + 1, j),
                    solve(text1, text2, i, j + 1)
                );
            }
        }
    
        int longestPalindromeSubseq(string s) {
            memset(dp, -1, sizeof(dp));  // Initialize dp array with -1
    
            string text1 = s;            // Original string
            string text2 = s;            
            reverse(text2.begin(), text2.end());  // Reversed string
    
            m = text1.length();
            n = text2.length();
    
            return solve(text1, text2, 0, 0);  // Start from 0,0
        }
    };

    // # Leetcode 516 - Longest Palindromic Subsequence

    // # 🧠 Intuition:
    // # A palindrome reads the same forwards and backwards.
    // # So, to find the longest palindromic subsequence in a string `s`,
    // # we reverse the string to get `rev_s` and find the Longest Common Subsequence (LCS) between `s` and `rev_s`.
    // # This LCS represents the longest sequence that appears in both the string and its reverse → hence a palindrome.
    
    // # 🧩 Approach:
    // # Use Top-Down Dynamic Programming (Memoization) to compute LCS between `s` and `rev_s`.
    // # If characters match, we add 1 and move diagonally.
    // # If not, we explore both skipping a char from either string and take the max.
    
    // # ⏱️ Time Complexity: O(n^2)
    // # We are solving each subproblem (i, j) once, where n is the length of the string.
    
    // # 🗃️ Space Complexity: O(n^2)
    // # 2D dp array of size [n][n] is used for memoization.
    
    // # ✅ Final Answer:
    // # Length of the longest palindromic subsequence in the string.
    
    