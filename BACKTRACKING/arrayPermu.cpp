#include <bits/stdc++.h>
using namespace std;
class Solution {
    public: 
        int n;  // Stores the size of the nums array
        int minScore = INT_MAX;  // Stores the minimum score found
        vector<int> resultPerm;  // Stores the permutation with the minimum score
    
        // Recursive backtracking function to generate permutations and calculate scores
        void solve(vector<int>& nums, vector<bool>& visited, vector<int>& perm, int score) {
            // Pruning: If the current score already exceeds minScore, stop exploring further
            if (score > minScore) {
                return;
            }
    
            // Base case: When a full permutation is formed
            if (perm.size() == n) {
                score += abs(perm.back() - nums[perm[0]]); // Add the circular difference
                if (minScore > score) {  // Update minScore and store the permutation if it's the best so far
                    minScore = score;
                    resultPerm = perm;
                }
                return;
            }
    
            // Try placing each number in the permutation
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {  // Ensure the number is not already used
                    visited[i] = true;  // Mark it as used
                    perm.push_back(i);  // Add it to the current permutation
                    int s = perm.size();
                    // Recursively explore further permutations while calculating score
                    solve(nums, visited, perm, score + abs(perm[s - 2] - nums[perm[s - 1]]));
                    visited[i] = false;  // Backtrack (undo the selection)
                    perm.pop_back();  // Remove the last added element
                }
            }
        }
    
        vector<int> findPermutation(vector<int>& nums) {
            n = nums.size();
            vector<bool> visited(n, false);  // Track visited elements
            vector<int> perm = {0};  // Start permutation with first element
            visited[0] = true;
    
            solve(nums, visited, perm, 0);  // Start the recursion
            return resultPerm;  // Return the best permutation found
        }
    };
    
//     # This C++ program finds a permutation of an array such that  LC 3149
// # the sum of absolute differences between consecutive elements is minimized.

// # Approach:
// # 1. Use backtracking to generate all possible permutations.
// # 2. Maintain a minimum score (sum of absolute differences).
// # 3. Prune (cut off) unnecessary recursive calls if the current score exceeds the minimum found so far.
// # 4. Store the permutation with the lowest score.
// # 5. Finally, return the best permutation.

// # Time Complexity:
// # - The approach generates O(n!) permutations in the worst case, making it exponential.
// # - However, pruning helps reduce unnecessary computations.
