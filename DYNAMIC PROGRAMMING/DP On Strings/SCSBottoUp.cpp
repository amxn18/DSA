#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      // Function to find length of shortest common supersequence of two strings.
      int shortestCommonSupersequence(string &s1, string &s2) {
          int m = s1.length();
          int n = s2.length();
  
          // Create DP table with (m+1)x(n+1) dimensions
          vector<vector<int>> dp(m+1, vector<int>(n+1));
  
          // Fill base cases
          for(int i = 0; i <= m; i++) dp[i][0] = i;
          for(int j = 0; j <= n; j++) dp[0][j] = j;
  
          // Fill the rest of the DP table
          for(int i = 1; i <= m; i++) {
              for(int j = 1; j <= n; j++) {
                  if(s1[i-1] == s2[j-1]) {
                      // Characters match → include once
                      dp[i][j] = 1 + dp[i-1][j-1];
                  } else {
                      // Characters don’t match → take min of both options
                      dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                  }
              }
          }
  
          // Final answer is in dp[m][n]
          return dp[m][n];
      }
  };

//   # GFG - Shortest Common Supersequence Length (Tabulation)

// # Approach:
// # - Bottom-Up DP
// # - dp[i][j] = min length of SCS of s1[0..i-1] and s2[0..j-1]
// # - If s1[i-1] == s2[j-1] → include once and move diagonally
// # - Else → take min of (skip s1 or skip s2), add 1

// # Base Cases:
// # - dp[i][0] = i (all from s1)
// # - dp[0][j] = j (all from s2)

// # Time Complexity: O(m * n)
// # Space Complexity: O(m * n)

  