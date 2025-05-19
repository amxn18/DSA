#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int m, n;
        int dp[501][501];  // Memoization table
    
        // Recursive helper function
        int solve(string word1, string word2, int i, int j) {
            // Base case: If word1 is exhausted → insert remaining word2 chars
            if(i == m) return n - j;
            // Base case: If word2 is exhausted → delete remaining word1 chars
            if(j == n) return m - i;
    
            // If already computed
            if(dp[i][j] != -1) return dp[i][j];
    
            // If characters match → move both pointers
            if(word1[i] == word2[j]) 
                return dp[i][j] = solve(word1, word2, i+1, j+1);
    
            // Operations: Insert, Delete, Replace
            int insert = 1 + solve(word1, word2, i, j+1);
            int del = 1 + solve(word1, word2, i+1, j);
            int replace = 1 + solve(word1, word2, i+1, j+1);
    
            // Take minimum of the three
            return dp[i][j] = min({insert, del, replace});
        }
    
        // Main function
        int minDistance(string word1, string word2) {
            m = word1.length();
            n = word2.length();
            memset(dp, -1, sizeof(dp));  // Initialize memo table
            return solve(word1, word2, 0, 0);
        }
    };
    // # 🔍 Problem: Leetcode 72 – Edit Distance

    // # 🎯 Goal:
    // #   Convert word1 → word2 with min operations:
    // #   - Insert
    // #   - Delete
    // #   - Replace
    
    // # 🧠 Approach:
    // #   - Recursively try all 3 operations and memoize.
    // #   - If chars match → no op, move forward.
    // #   - Else → try all ops and take min.
    
    // # 🕒 Time: O(m * n)
    // # 🗂️ Space: O(m * n)
    
    