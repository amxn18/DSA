#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestCommonSubsequence(string s1, string s2) {
            int m = s1.length();
            int n = s2.length();
    
            // Step 1: Build the DP table
            vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
    
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1[i - 1] == s2[j - 1])
                        t[i][j] = 1 + t[i - 1][j - 1];
                    else
                        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
    
            // Step 2: Trace back to construct the LCS string
            string lcs = "";
            int i = m, j = n;
            while (i > 0 && j > 0) {
                if (s1[i - 1] == s2[j - 1]) {
                    lcs.push_back(s1[i - 1]);
                    i--; j--;
                } else {
                    if (t[i - 1][j] > t[i][j - 1])
                        i--;
                    else
                        j--;
                }
            }
    
            // Since we added characters in reverse order
            reverse(begin(lcs), end(lcs));
            cout << "LCS: " << lcs << endl;
    
            // Return the length of the LCS
            return t[m][n];
        }
    };

//     # Leetcode 1143 - Longest Common Subsequence (with string print)

// # Step 1: Create a DP table t[m+1][n+1]
// #         - t[i][j] = LCS length for s1[0..i-1], s2[0..j-1]

// # Step 2: Fill the table:
// #         - If s1[i-1] == s2[j-1] → t[i][j] = 1 + t[i-1][j-1]
// #         - Else → t[i][j] = max(t[i-1][j], t[i][j-1])

// # Step 3: Traceback from bottom-right:
// #         - If match → include char in LCS, move diagonally
// #         - Else → move to the direction of greater value

// # Step 4: Reverse the string (since it’s built backward)
// #         - Output actual LCS string
// #         - Return LCS length

// # Time Complexity: O(m * n)
// # Space Complexity: O(m * n)

    