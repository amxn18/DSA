#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n; // Number of words
    
        // Function to check if 'prev' is a predecessor of 'curr'
        bool isPred(string& prev, string& curr) {
            int a = prev.length();
            int b = curr.length();
            
            // 'prev' should be exactly one character shorter than 'curr'
            if (a >= b || b - a != 1) {  
                return false;
            }
    
            int i = 0, j = 0;
            while (i < a && j < b) {
                if (prev[i] == curr[j]) i++; // Match character
                j++; // Move to next character in curr
            }
            return i == a; // If all characters of 'prev' matched in order
        }
    
        // Sorting function to sort words based on length (shortest to longest)
        static bool lambda(string& w1, string& w2) {
            return w1.length() < w2.length();
        }
    
        int longestStrChain(vector<string>& words) {
            n = words.size();
            
            // Step 1: Sort words by length
            sort(begin(words), end(words), lambda);
    
            // Step 2: DP array to store the longest chain ending at each word
            vector<int> dp(n, 1);
            int maxL = 1; // Track max chain length
    
            // Step 3: Nested loop to check predecessor relationship
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (isPred(words[j], words[i])) { // Check if words[j] → words[i] forms a chain
                        dp[i] = max(dp[i], dp[j] + 1); // Update longest chain at i
                        maxL = max(maxL, dp[i]); // Update global max chain length
                    }
                }
            }
    
            return maxL; // Return the longest word chain length
        }
    };
    // # Leetcode 1048: Longest String Chain

    // # Approach: Bottom-Up Dynamic Programming (Tabulation)
    
    // # 1. Sort words by length (shortest to longest) -> O(N log N)
    // # 2. Use DP array `dp[i]`, where dp[i] stores longest chain ending at words[i]
    // # 3. Check if `words[j]` is a valid predecessor of `words[i]` using `isPred()`
    // #    - Must be exactly 1 character shorter
    // #    - Can be converted by removing 1 character
    // # 4. If valid, update dp[i] = max(dp[i], dp[j] + 1)
    // # 5. Track the maximum chain length
    
    // # Time Complexity: O(N² * L) 
    // #    - Sorting takes O(N log N)
    // #    - Nested loop checks O(N²) pairs
    // #    - Each `isPred()` runs in O(L), where L is max word length
    // # Space Complexity: O(N) 
    // #    - DP array stores N values
        