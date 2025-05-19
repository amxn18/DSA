#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dp[1001][1001]; // DP array to memoize results for substring i to j
    
        // Recursive function to compute LPS length in substring s[i...j]
        int solve(string& s, int i, int j) {
            if(i > j) return dp[i][j] = 0; // Empty substring
            if(dp[i][j] != -1) return dp[i][j]; // Return if already computed
            if(i == j) return dp[i][j] = 1; // Single character is always a palindrome
    
            if(s[i] == s[j])
                return dp[i][j] = 2 + solve(s, i + 1, j - 1); // Characters match, add 2 and move inward
            else
                return dp[i][j] = max(solve(s, i + 1, j), solve(s, i, j - 1)); // Take max by excluding one end
        }
    
        int longestPalindromeSubseq(string s) {
            memset(dp, -1, sizeof(dp)); // Initialize DP array with -1
            int n = s.length();
            return solve(s, 0, n - 1); // Start solving from full string
        }
    };
    // # Leetcode 516 - Longest Palindromic Subsequence

    // # 🧠 Intuition:
    // # The longest palindromic subsequence (LPS) can be found by comparing characters from both ends.
    // # If characters at both ends match, we include them in the LPS and move inward.
    // # If they don't match, we explore both options: excluding one character at a time.
    
    // # 🧩 Approach (Top-Down Memoization):
    // # 1. Use recursion to solve the problem for substring s[i...j].
    // # 2. Memoize the results using a 2D array dp[i][j].
    // # 3. Base cases:
    // #    - If i > j, return 0 (invalid/empty substring).
    // #    - If i == j, return 1 (single character is always a palindrome).
    // # 4. If s[i] == s[j], include both ends and add 2 + LPS(s[i+1...j-1]).
    // # 5. Else, take the maximum of LPS(s[i+1...j]) and LPS(s[i...j-1]).
    
    // # ⏱️ Time Complexity: O(n^2)
    // # Because we solve each substring s[i...j] only once and store it in dp[i][j].
    
    // # 🗃️ Space Complexity: O(n^2)
    // # Due to the dp array of size n x n used to store intermediate results.
    
    // # ✅ Final Output:
    // # Length of the longest palindromic subsequence in the given string using memoized recursion.
        