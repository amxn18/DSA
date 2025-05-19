#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:  
        int dp[1001][1001];
    
        // Helper function to check if substring s[i..j] is a palindrome using memoization
        bool solve(string& s, int i, int j){
            if(i >= j) return true; // Base case: single char or empty substring is palindrome
            if(dp[i][j] != -1) return dp[i][j]; // Already computed
    
            // Check both ends and recurse inwards
            if(s[i] == s[j]) 
                return dp[i][j] = solve(s, i + 1, j - 1);
            
            return dp[i][j] = false; // Not a palindrome
        }
    
        string longestPalindrome(string s) {
            int n = s.length();
            memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
    
            int maxlen = 0; // Track max length
            int sp = 0;     // Track starting point of longest palindrome
    
            // Check all substrings s[i..j]
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    if(solve(s, i, j)){
                        if(j - i + 1 > maxlen){
                            maxlen = j - i + 1;
                            sp = i;
                        }
                    }
                }
            }
    
            // Return the longest palindromic substring
            return s.substr(sp, maxlen);
        }
    };

    // # 📌 Leetcode 5: Longest Palindromic Substring

    // # ✅ Approach:
    // # - Use recursion + memoization to check if substring s[i..j] is a palindrome.
    // # - For every possible substring (i, j), check if it's a palindrome.
    // # - Track the longest one found so far.
    
    // # 🧠 Intuition:
    // # - A substring is a palindrome if:
    // #     s[i] == s[j] && s[i+1..j-1] is a palindrome.
    // # - Use a DP table to memoize overlapping subproblems (i, j).
    
    // # ⏱️ Time Complexity:
    // # O(n^2) — two nested loops for all substrings + O(1) memoized checks.
    
    // # 💾 Space Complexity:
    // # O(n^2) — for the DP table (1001 x 1001).
    
    // # 🧪 Example:
    // # Input:  "babad"
    // # Output: "bab" or "aba" (both are valid)
    
    // # 🔁 Flow:
    // # 1. Loop through all i to j ranges
    // # 2. Use recursive function `solve` to check if s[i..j] is a palindrome
    // # 3. Store results in dp[i][j] to avoid recomputation
    // # 4. Keep track of the longest length and starting index
    // # 5. Return the longest palindromic substring using substr(start, len)
    