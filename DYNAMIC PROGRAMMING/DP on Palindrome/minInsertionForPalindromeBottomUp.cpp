#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minInsertions(string s) {
            int n = s.length();
    
            // dp[i][j] will store the minimum insertions needed to make s[i...j] a palindrome
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            // Strings of length 1 are already palindromes, so dp[i][i] = 0 by default
    
            // l is the length of the current substring
            for (int l = 2; l <= n; l++) {
                for (int i = 0; i <= n - l; i++) {
                    int j = i + l - 1;
    
                    if (s[i] == s[j]) {
                        // If characters match, no insertion needed between i and j
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {
                        // Insert 1 character and take min of both choices
                        dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            // Answer is for the whole string from 0 to n-1
            return dp[0][n - 1];
        }
    };

    // # Leetcode 1312 - Minimum Insertions to Make a String Palindrome

    // # 🔍 Problem:
    // # Find the minimum number of insertions required to make a given string a palindrome.
    
    // # 🧠 Logic:
    // # - If characters at both ends match, no insertions needed → shrink window.
    // # - If not, insert a character to make them match, and take the minimum of two possibilities.
    
    // # ✅ Approach:
    // # - Bottom-up Dynamic Programming
    // # - dp[i][j] = min insertions needed to make substring s[i...j] a palindrome
    // # - dp[i][i] = 0 → single character is already a palindrome
    // # - Build solutions for substrings of increasing length
    
    // # ⏱️ Time Complexity:
    // # - O(n^2) → we fill a 2D DP table of size n x n
    
    // # 🧠 Space Complexity:
    // # - O(n^2) → due to the 2D dp array
    
    // # 📦 Input:
    // # - string s (length ≤ 500)
    
    // # 🔁 Output:
    // # - int → minimum insertions needed
    
    // # ✅ Example:
    // # Input: "abcda"
    // # Output: 2 (Insert 'd' and 'b' → "abcdcba")
    
    // # 🔧 Key Insight:
    // # - Equivalent to finding longest palindromic subsequence (LPS)
    // #   and subtracting it from total length → min insertions = n - LPS
    