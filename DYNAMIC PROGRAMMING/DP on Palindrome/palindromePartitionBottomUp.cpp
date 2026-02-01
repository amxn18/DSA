#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            int n = s.size();
            vector<vector<bool>> isPal(n, vector<bool>(n, false));
            vector<vector<vector<string>>> dp(n + 1);
    
            dp[n] = {{}};
    
            // Preprocess palindromic substrings
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j) {
                    if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) {
                        isPal[i][j] = true;
                    }
                }
            }
    
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j) {
                    if (isPal[i][j]) {
                        string part = s.substr(i, j - i + 1);
                        for (auto& rest : dp[j + 1]) {
                            vector<string> current = {part};
                            current.insert(current.end(), rest.begin(), rest.end());
                            dp[i].push_back(current);
                        }
                    }
                }
            }
    
            return dp[0];
        }
    };
    // # 🧮 Bottom-Up (Tabulation) | Leetcode 131 - Palindrome Partitioning

    // - First preprocess all palindromic substrings using a DP table: isPal[i][j].
    // - Then build the answer from back to front using a DP array dp[i]:
    //   dp[i] stores all valid partitions for substring s[i...n-1].
    // - For each position, find all palindromic substrings and append them to
    //   the partitions stored in dp[j+1] (rest of the string).
    // - Combines known future results to build current result.
    
    // Time Complexity:    O(N^2 + N * 2^N) → Palindrome check + building all partitions
    // Space Complexity:   O(N^2 + N * 2^N) → Palindrome table + dp array
    