#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dp[501][501];
    
        // Recursive function to find minimum insertions
        int solve(string &s, int i, int j) {
            // Base case: if i >= j, string is already a palindrome
            if (i >= j) return 0;
    
            // If already computed, return the stored value
            if (dp[i][j] != -1) return dp[i][j];
    
            // If characters match, move inward
            if (s[i] == s[j])
                return dp[i][j] = solve(s, i + 1, j - 1);
    
            // Else, insert a character either at i or at j and choose min
            return dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
        }
    
        int minInsertions(string s) {
            int n = s.length();
            memset(dp, -1, sizeof(dp));
            return solve(s, 0, n - 1);
        }
    };

    // # Leetcode 1312 - Minimum Insertions to Make a String Palindrome

    // # 🔍 Problem:
    // # Given a string s, return the minimum number of insertions needed to make s a palindrome.
    
    // # 🧠 Logic:
    // # - To make a string a palindrome, we insert characters to match from both ends.
    // # - If s[i] == s[j], no insertions are needed, move inwards.
    // # - Else, insert a character at i or j to match and recurse.
    // # - Use memoization to avoid recomputation.
    
    // # ✅ Approach:
    // # - Top-Down DP (Memoization)
    // # - dp[i][j] stores the minimum insertions needed for substring s[i...j]
    // # - Base case: if i >= j, it's already a palindrome
    // # - If s[i] == s[j] → no insertion → check s[i+1...j-1]
    // # - Else → 1 + min(insert at i, insert at j)
    
    // # ⏱️ Time Complexity:
    // # - O(n^2) due to all pairs (i, j)
    
    // # 🧠 Space Complexity:
    // # - O(n^2) for the dp array
    
    // # 📦 Input:
    // # - String s (length ≤ 500)
    
    // # 🔁 Output:
    // # - Integer: minimum number of insertions
    
    // # 🛠️ Functions Used:
    // # - solve(s, i, j): recursive helper with memoization
    // # - memset(dp, -1, sizeof(dp)): initialize all dp values to -1
    
    // # ✅ Example:
    // # s = "abcaa"
    // # Output: 1 (Insert 'b' at the end → "abcaab")
    