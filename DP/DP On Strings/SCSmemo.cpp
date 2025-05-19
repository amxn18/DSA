#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int m, n;
      int dp[501][501]; // DP table to memoize results
  
      // Recursive function to calculate SCS length
      int solve(string &s1, string &s2, int i, int j){
          // If we reached end of s1, return remaining length of s2
          if(i == m) return n - j;
  
          // If we reached end of s2, return remaining length of s1
          if(j == n) return m - i;
  
          // If already computed, return stored value
          if(dp[i][j] != -1) return dp[i][j];
  
          // If characters match, take 1 and move both pointers
          if(s1[i] == s2[j]){
              return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
          } 
          // Else, try both options: skip from s1 or skip from s2
          else {
              return dp[i][j] = min(
                  1 + solve(s1, s2, i+1, j),  // Include s1[i]
                  1 + solve(s1, s2, i, j+1)   // Include s2[j]
              );
          }
      }
  
      int shortestCommonSupersequence(string &s1, string &s2) {
          m = s1.length();
          n = s2.length();
  
          // Initialize dp table with -1
          memset(dp, -1, sizeof(dp));
  
          // Start recursion from i=0, j=0
          return solve(s1, s2, 0, 0);
      }
  };
//   # GFG - Shortest Common Supersequence Length

//   # Approach:
//   # - If s1[i] == s2[j] → include once, move both i & j
//   # - Else → choose min(1 + skip from s1, 1 + skip from s2)
//   # - Base cases:
//   #     - If i reaches end of s1 → return remaining of s2
//   #     - If j reaches end of s2 → return remaining of s1
  
//   # DP[i][j] = min SCS length for s1[i:] and s2[j:]
  
//   # Time Complexity: O(m * n)
//   # Space Complexity: O(m * n)
    