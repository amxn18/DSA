#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> result; // Stores all valid combinations
    
        // Backtracking function to generate combinations
        void solve(int start, int &n, int k, vector<int>& temp) {
            // Base condition: If we have selected 'k' elements, add to result
            if (k == 0) {
                result.push_back(temp);
                return;
            }
    
            // Iterate from 'start' to 'n' to generate combinations
            for (int i = start; i <= n; i++) {
                temp.push_back(i);      // Choose the current element
                solve(i + 1, n, k - 1, temp); // Recursively choose the next elements
                temp.pop_back();        // Backtrack to explore other possibilities
            }
        }
    
        vector<vector<int>> combine(int n, int k) {
            vector<int> temp;  // Temporary vector to store the current combination
            solve(1, n, k, temp); // Start generating combinations from 1 to n
            return result;
        }
    };
//     backtracking approach used in the C++ code for Leetcode 77 (Combinations).

// # Function to generate all possible combinations of 'k' numbers from 1 to 'n'.
// # Uses backtracking to explore all possibilities.

// # 1. Base Condition: If 'k' elements are selected, add them to the result.
// # 2. Loop from 'start' to 'n' to select numbers one by one.
// # 3. Recursively call the function with (i+1) to ensure unique combinations.
// # 4. Backtrack by removing the last added element to explore new paths.

// # Time Complexity: O(C(n, k)) = O(n! / (k! * (n-k)!)) (as we generate all combinations).