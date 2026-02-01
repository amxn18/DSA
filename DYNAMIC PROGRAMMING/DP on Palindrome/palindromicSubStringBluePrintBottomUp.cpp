#include <bits/stdc++.h>
using namespace std;

// Leetcode 647: Palindromic Substrings
class Solution {
    public:
        int countSubstrings(string s) {
            int n = s.length();
    
            // dp[i][j] will be true if the substring s[i..j] is a palindrome
            vector<vector<bool>> dp(n, vector<bool>(n, false));
    
            int count = 0;
    
            // l = length of substring
            for(int l = 1; l <= n; l++) {
                for(int i = 0; (i + l - 1) < n; i++) {
                    int j = i + l - 1;  // End index of current substring
    
                    if(i == j) {
                        // Case 1: Single character → Always a palindrome
                        dp[i][j] = true;
                    }
                    else if(i + 1 == j) {
                        // Case 2: Two characters → Check if both are equal
                        dp[i][j] = (s[i] == s[j]);
                    }
                    else {
                        // Case 3: More than two characters → Check ends and inner substring
                        dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                    }
    
                    // If substring s[i..j] is palindrome, increment count
                    if(dp[i][j] == true) count++;
                }
            }
    
            return count;
        }
    };
    

// # Leetcode 647: Count Substrings (Bottom-Up DP)

// # Goal:
// #   Count the total number of palindromic substrings in a string.

// # Approach:
// #   - Use tabulation DP with dp[i][j] indicating if s[i..j] is a palindrome.
// #   - Loop over all substring lengths from 1 to n.
// #     For each length l:
// #       - Compute j = i + l - 1 (end index)
// #       - For each i (start index), check if:
// #           1. i == j      → single character → always palindrome
// #           2. i + 1 == j  → two characters → check s[i] == s[j]
// #           3. else        → s[i] == s[j] && dp[i+1][j-1] (inner string is palindrome)
// #   - Count how many times dp[i][j] is true.

// # Time Complexity:
// #   O(n^2) – Two nested loops over all substrings

// # Space Complexity:
// #   O(n^2) – DP table of size n x n

// # Note:
// #   - This is a bottom-up approach and avoids recursion overhead.
// #   - Efficient and clean for strings up to 1000 characters.
