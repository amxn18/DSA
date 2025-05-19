#include <bits/stdc++.h>
using namespace std;
//  LC 1642 Using recursion and memoization(dp)  Not optimal --> memory limit exceeded(Constaraint for height vector)
class Solution {
    public:
        int n;
        unordered_map<string, int> dp; // Memoization map
    
        int solve(int i, vector<int>& heights, int bricks, int ladders) {
            if (i == n - 1) return 0;
    
            string key = to_string(i) + "-" + to_string(bricks) + "-" + to_string(ladders);
            if (dp.find(key) != dp.end()) return dp[key]; // Return cached result
    
            if (heights[i] >= heights[i + 1]) {
                return dp[key] = 1 + solve(i + 1, heights, bricks, ladders);
            } else {
                int byBricks = 0, byLadders = 0;
                int diff = heights[i + 1] - heights[i];
    
                if (bricks >= diff) {
                    byBricks = 1 + solve(i + 1, heights, bricks - diff, ladders);
                }
                if (ladders > 0) {
                    byLadders = 1 + solve(i + 1, heights, bricks, ladders - 1);
                }
    
                return dp[key] = max(byBricks, byLadders);
            }
        }
    
        int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
            n = heights.size();
            return solve(0, heights, bricks, ladders);
        }
    };
//     # Memoization is a technique used to store the results of expensive function calls
// # and reuse them when the same inputs occur again. It helps optimize recursive solutions
// # by avoiding redundant calculations.

// # In this solution:
// # - We use an unordered_map to cache results for (i, bricks, ladders).
// # - Before making a recursive call, we check if the result is already computed.
// # - This prevents recomputation and improves efficiency.

// # Time Complexity: O(n * b * l) (where b = bricks, l = ladders)
// # Space Complexity: O(n * b * l) (for memoization storage)
