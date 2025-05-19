#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dp[2001];  // dp[i] will store the minimum cuts needed for substring s[i..end]
    
        // Helper function to check if a substring is a palindrome
        bool isPalindrome(string& s, int i, int j) {
            while(i < j) {
                if(s[i++] != s[j--]) return false;
            }
            return true;
        }
    
        // Recursive function to find the minimum number of cuts from index i to end
        int solve(string& s, int i) {
            // If we reach the end of the string, no more cuts are needed
            if(i == s.length()) return 0;
    
            // If already computed, return the stored result
            if(dp[i] != -1) return dp[i];
    
            int result = INT_MAX;
    
            // Try all possible palindromic partitions starting from index i
            for(int j = i; j < s.length(); j++) {
                // If s[i..j] is a palindrome, make a cut after j and solve for the rest
                if(isPalindrome(s, i, j)) {
                    int cuts = 1 + solve(s, j + 1);  // 1 for the current cut
                    result = min(result, cuts);
                }
            }
    
            return dp[i] = result;  // Store and return the minimum cuts from index i
        }
    
        int minCut(string s) {
            memset(dp, -1, sizeof(dp));  // Initialize dp array
            return solve(s, 0) - 1;      // Subtract 1 as the last part doesn't need a cut
        }
    };
    // # Problem: Palindrome Partitioning II
    // # Approach: Recursion + Memoization
    // # isPalindrome(i,j) checks if substring s[i..j] is palindrome
    // # solve(i): for every j >= i, if s[i..j] is palindrome,
    // #           make 1 cut and recursively solve from j+1 onwards
    // #           Take minimum among all valid cuts
    // # Return solve(0) - 1 because the final segment doesn't need a cut
    
    // # Time: O(N^3) (due to O(N^2) isPalindrome checks inside recursion)
    // # Space: O(N) for dp + O(N) recursion stack
        