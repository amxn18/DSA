#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int n;
        int dp[1001][1001];  // DP table for memoization
    
        // Function to check if `prev` is a valid predecessor of `curr`
        bool isPred(string& prev, string& curr) {
            int a = prev.length();
            int b = curr.length();
            
            // `prev` must be exactly 1 character shorter than `curr`
            if (a >= b || b - a != 1) {  
                return false;
            }
    
            int i = 0, j = 0;
            while (i < a && j < b) {
                if (prev[i] == curr[j]) i++; // Match characters
                j++; // Move to next character in `curr`
            }
            
            return i == a; // If all characters of `prev` are matched in `curr`
        }
    
        // Recursive function with memoization
        int solve(int idx, int prev, vector<string>& words) {
            if (idx >= n) return 0; // Base case: no more words left
    
            // Use memoization to avoid recomputation
            if (prev != -1 && dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
    
            int taken = 0, leave = 0;
            
            // If `prev` is -1 (first word) OR `prev` is a valid predecessor of `idx`
            if (prev == -1 || isPred(words[prev], words[idx])) {
                taken = 1 + solve(idx + 1, idx, words); // Include current word
            }
            
            leave = solve(idx + 1, prev, words); // Exclude current word
    
            // Store result in DP table
            if (prev != -1) {
                return dp[idx][prev + 1] = max(taken, leave);
            }
            return max(taken, leave);
        }
    
        // Custom comparator to sort words by length (shorter words come first)
        static bool lambda(string& w1, string& w2) {
            return w1.length() < w2.length();
        }
    
        int longestStrChain(vector<string>& words) {
            n = words.size();
            sort(begin(words), end(words), lambda); // Sort words based on length
            
            // Initialize DP table with -1
            memset(dp, -1, sizeof(dp));
    
            return solve(0, -1, words); // Start recursion
        }
    };

    // # Leetcode 1048: Longest String Chain

    // # Approach: Recursion + Memoization (Top-Down DP)
    
    // # 1. Sort words by length (shortest to longest) -> O(N log N)
    // # 2. Use recursion with memoization (Top-Down DP) -> O(N²)
    // # 3. Define `isPred()` to check if a word is a valid predecessor:
    // #    - Must be exactly 1 character shorter
    // #    - Can be converted by removing 1 character
    // # 4. Recursively:
    // #    - Include word if it extends the chain
    // #    - Exclude word and continue
    // # 5. Use memoization (dp[idx][prev]) to avoid redundant calculations
    // # 6. Return the longest valid chain length
    
    // # Time Complexity: O(N²)
    // #    - Sorting takes O(N log N)
    // #    - DP recursion takes O(N²)
    // # Space Complexity: O(N²)
    // #    - DP table stores results for N * N states
    // #    - Recursion stack depth at most O(N)
    