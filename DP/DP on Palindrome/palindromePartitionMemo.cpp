#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> memo[17];  // max string size = 16
        bool computed[17] = {false};
    
        bool isPalindrome(string& s, int i, int j) {
            while (i < j) {
                if (s[i++] != s[j--]) return false;
            }
            return true;
        }
    
        vector<vector<string>> dfs(string& s, int start) {
            if (start == s.length()) return {{}};
            if (computed[start]) return memo[start];
    
            vector<vector<string>> result;
    
            for (int end = start; end < s.length(); end++) {
                if (isPalindrome(s, start, end)) {
                    string part = s.substr(start, end - start + 1);
                    for (auto& sub : dfs(s, end + 1)) {
                        result.push_back({part});
                        result.back().insert(result.back().end(), sub.begin(), sub.end());
                    }
                }
            }
    
            computed[start] = true;
            return memo[start] = result;
        }
    
        vector<vector<string>> partition(string s) {
            return dfs(s, 0);
        }
    };
    // # 🔁 Recursion + Memoization | Leetcode 131 - Palindrome Partitioning

    // - At each index `start`, recursively check all substrings `s[start..end]`.
    // - If it's a palindrome, include it and recurse for the rest of the string.
    // - Use memoization to avoid recomputing results from the same start index.
    // - The recursive call builds all valid partitions by exploring palindromic cuts.
    
    // Time Complexity:    O(N * 2^N)   → N = length of string, 2^N = all partitions
    // Space Complexity:   O(N * 2^N)   → Storing all possible partitions + memo table
        