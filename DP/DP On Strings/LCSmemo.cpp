#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int m, n;
        int dp[1001][1001];
    
        // Recursive function with memoization
        int solve(string& text1, string& text2, int i, int j) {
            // Base case: if either string is fully traversed
            if (i >= m || j >= n) return 0;
    
            // Return cached result if already computed
            if (dp[i][j] != -1) return dp[i][j];
    
            // If characters match, move both pointers
            if (text1[i] == text2[j]) {
                return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1);
            } 
            // Else, take the max by skipping one character from either string
            else {
                return dp[i][j] = max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
            }
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            // Initialize class members for use in solve()
            m = text1.length();
            n = text2.length();
    
            // Initialize dp array with -1
            memset(dp, -1, sizeof(dp));
    
            // Start recursion from index 0 of both strings
            return solve(text1, text2, 0, 0);
        }
    };

//     # Leetcode 1143 - Longest Common Subsequence

// # Approach:
// #   - Use Top-Down Dynamic Programming (Recursion + Memoization)
// #   - dp[i][j] = LCS length of substrings text1[i:] and text2[j:]
// #   - If characters match: 1 + dp[i+1][j+1]
// #   - Else: max(dp[i+1][j], dp[i][j+1])
// #   - Base Case: If either string ends, return 0
// #   - Final Answer: dp[0][0]

// # Time Complexity: O(m * n)
// #   - Each state (i, j) is computed once due to memoization

// # Space Complexity: O(m * n)
// #   - DP table of size m x n
// #   - Recursion stack depth up to O(m + n)

// # Optimization Note:
// #   - Can be converted to Bottom-Up Tabulation or Space Optimized to O(n)

    