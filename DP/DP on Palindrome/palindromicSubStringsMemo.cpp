#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dp[1001][1001];
    
        // Recursive function to check if s[i..j] is a palindrome
        bool check(string& s, int i, int j) {
            if(i > j) return true; // Empty or single char is a palindrome
            if(dp[i][j] != -1) return dp[i][j]; // Return memoized result
    
            if(s[i] == s[j]) {
                // If characters match, check the inner substring
                return dp[i][j] = check(s, i+1, j-1);
            }
    
            return dp[i][j] = false; // If characters don't match
        }
    
        int countSubstrings(string s) {
            int n = s.length();
            int count = 0;
            memset(dp, -1, sizeof(dp)); // Initialize dp table
    
            // Try all possible substrings
            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    if(check(s, i, j)) count++;
                }
            }
            return count;
        }
    };

//     # Leetcode 647: Count Substrings (Palindromic)

// # Goal:
// #   Count total number of substrings in the string that are palindromes.

// # Approach:
// #   - Try all substrings s[i..j] using 2 nested loops.
// #   - Use recursion with memoization (dp[i][j]) to check if s[i..j] is a palindrome.
// #   - If s[i] == s[j], check if the inner substring s[i+1..j-1] is also palindrome.
// #   - If yes, increment the count.

// # Time Complexity:
// #   O(n^2) → for all (i, j) substring pairs.
// #   Each check uses memoization, so no re-computation.

// # Space Complexity:
// #   O(n^2) → dp[i][j] table for memoization (n <= 1000).

// # Note:
// #   - Substrings are continuous characters.
// #   - i varies from 0 to n-1, and j from i to n-1.
