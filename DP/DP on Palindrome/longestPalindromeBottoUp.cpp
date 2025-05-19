#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.length();
            vector<vector<bool>> dp(n, vector<bool>(n, false));
            int maxLen = 1;     // Minimum palindromic substring length is 1
            int idx = 0;        // Starting index of longest palindromic substring
    
            // All substrings of length 1 are palindromes
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
    
            // Check all lengths from 2 to n
            for (int l = 2; l <= n; l++) {
                for (int i = 0; i <= n - l; i++) {
                    int j = i + l - 1;  // Ending index
    
                    if (s[i] == s[j]) {
                        if (l == 2) {
                            dp[i][j] = true;  // Substring of 2 equal chars is a palindrome
                        } else {
                            dp[i][j] = dp[i + 1][j - 1];  // Depends on the inner substring
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
    
    // # 📌 Leetcode 5: Longest Palindromic Substring

    // # ✅ Approach:
    // # - Use bottom-up Dynamic Programming (tabulation)
    // # - dp[i][j] = true if s[i..j] is a palindrome
    // # - Start with substrings of length 1 → up to n
    
    // # 🧠 Intuition:
    // # A substring s[i..j] is a palindrome if:
    // # - s[i] == s[j] AND
    // # - s[i+1..j-1] is also a palindrome
    
    // # ⏱️ Time Complexity:
    // # O(n^2) — two nested loops for lengths and starting points
    
    // # 💾 Space Complexity:
    // # O(n^2) — for 2D DP table
    
    // # 🧪 Example:
    // # Input:  "babad"
    // # Output: "bab" or "aba"
    
    // # 🔁 Flow:
    // # - Initialize dp[i][i] = true (single letters)
    // # - Check substrings of length 2, then 3, up to n
    // # - Update maxLen and idx whenever a longer palindrome is found
    // # - Return substring starting at idx with length maxLen
    