#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minCut(string s) {
            int n = s.length();
    
            // dp[i][j] tells whether the substring s[i...j] is a palindrome
            vector<vector<bool>> dp(n, vector<bool>(n, false));
    
            // Every single character is a palindrome
            for(int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
    
            // Check for substrings of length 2 to n
            for(int l = 2; l <= n; l++) {
                for(int i = 0; i < n - l + 1; i++) {
                    int j = i + l - 1;
    
                    if(l == 2) 
                        dp[i][j] = (s[i] == s[j]);  // Two chars are palindrome if equal
                    else 
                        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]); // Check inner substring
                }
            }
    
            // tell[i] will store the minimum cuts needed for substring s[0..i]
            vector<int> tell(n);
    
            for(int i = 0; i < n; i++) {
                if(dp[0][i]) {
                    tell[i] = 0;  // Whole substring s[0..i] is a palindrome → 0 cuts
                } else {
                    tell[i] = INT_MAX;
                    for(int k = 0; k < i; k++) {
                        if(dp[k + 1][i] && tell[k] + 1 < tell[i]) {
                            tell[i] = 1 + tell[k];  // Cut after k if s[k+1..i] is palindrome
                        }
                    }
                }
            }
    
            return tell[n - 1];  // Minimum cuts needed for entire string
        }
    };
    // Leetcode 132: Palindrome Partitioning II

    // Goal: 
    //     Partition the string such that every substring is a palindrome. 
    //     Return the minimum cuts needed.
    
    // 🔸 Recursion + Memoization:
    //     - Approach: Try every cut position and use a helper to check palindromes.
    //     - Memoize from index i to end using dp[i].
    //     - Subtract 1 from final answer since last part doesn't need a cut.
    
    // 🔸 Bottom-Up DP:
    //     - Step 1: Precompute all palindromic substrings using a 2D dp[i][j].
    //     - Step 2: For each index i, use tell[i] to store min cuts to reach i.
    //     - If s[0..i] is a palindrome → 0 cuts.
    //     - Else, try all partitions k < i, if s[k+1..i] is a palindrome:
    //         → tell[i] = min(tell[i], 1 + tell[k])
    
    // ⏱ Time Complexity:
    //     - O(n^2) for filling dp[i][j] table + O(n^2) for computing tell[]
    //     - Overall: O(n^2)
    
    // 📦 Space Complexity:
    //     - O(n^2) for palindrome dp table
    //     - O(n) for tell[] array
    
        