#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int N, M, K;
        int MOD = 1e9 + 7;
        int dp[51][51][101]; // DP table for memoization
    
        // Recursive function with memoization
        int solve(int idx, int searchCost, int maxi) {
            // Base case: If we reached the end of the array
            if (idx == N) {
                return (searchCost == K) ? 1 : 0;
            }
    
            // Return memoized result if already computed
            if (dp[idx][searchCost][maxi] != -1) return dp[idx][searchCost][maxi];
    
            int result = 0;
    
            // Try placing each number from 1 to M
            for (int i = 1; i <= M; i++) {
                if (i > maxi) { 
                    // If i is a new max, increment searchCost
                    result = (result + solve(idx + 1, searchCost + 1, i)) % MOD;
                } else {
                    // Otherwise, keep the same searchCost
                    result = (result + solve(idx + 1, searchCost, maxi)) % MOD;
                }
            }
    
            // Store and return the result
            return dp[idx][searchCost][maxi] = result;
        }
    
        // Main function to initialize DP and start recursion
        int numOfArrays(int n, int m, int k) {
            N = n;
            M = m;
            K = k;
            memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
            return solve(0, 0, 0);  // Start with index 0, searchCost 0, and max 0
        }
    };
    
//     # LeetCode 1420: Build Array Where You Can Find The Maximum Exactly K Comparisons

// # Approach:
// # - We use recursion with memoization to solve the problem.
// # - Define a function `solve(idx, searchCost, maxi)`:
// #   - idx -> current index in the array.
// #   - searchCost -> number of times a new maximum is found.
// #   - maxi -> current maximum value in the array.
// # - Base Case:
// #   - If idx == N (end of array), check if searchCost == K.
// #   - If true, return 1 (valid array found), else return 0.
// # - Recursive Case:
// #   - Try placing numbers from 1 to M at index `idx`.
// #   - If `i > maxi`, it means a new maximum is found, so we increase `searchCost`.
// #   - Otherwise, keep the same `searchCost`.
// #   - Use memoization to store computed results to avoid redundant calculations.

// # Time Complexity: O(N * K * M^2)
// # - Each index (N) considers `K` search costs and iterates over `M` numbers.
// # - In the worst case, this results in O(N * K * M^2) operations.

// # Space Complexity: O(N * K * M)
// # - We use a DP table of size `dp[51][51][101]`, requiring O(N * K * M) memory.