#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int result  = INT_MAX; // Stores the minimum unfairness (max cookies assigned to any child)
        int n; // Number of cookies
    
        // Backtracking function to distribute cookies
        void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
            // Base case: If all cookies are assigned
            if (idx >= n) {
                int unfairness = *max_element(begin(children), end(children)); // Find max cookies assigned to any child
                result = min(result, unfairness); // Update the result with the minimum unfairness found
                return;
            }
    
            int cookie = cookies[idx]; // Current cookie to be assigned
    
            // Try assigning the current cookie to each child
            for (int i = 0; i < k; i++) {
                children[i] += cookie; // Give the current cookie to the i-th child
                solve(idx + 1, cookies, children, k); // Recur for the next cookie
                children[i] -= cookie; // Backtrack: Remove the assigned cookie and try the next possibility
            }
        }
    
        int distributeCookies(vector<int>& cookies, int k) {
            n = cookies.size(); // Total number of cookies
            vector<int> children(k, 0); // Stores the number of cookies assigned to each child
            solve(0, cookies, children, k); // Start backtracking from the 0th cookie
            return result; // Return the minimum unfairness
        }
    };

// # Problem: Distribute 'n' cookies among 'k' children, minimizing unfairness.
// # Unfairness = Max number of cookies assigned to any child.

// # Approach: Backtracking
// # - Try giving each cookie to every child.
// # - Track the max cookies assigned to any child (unfairness).
// # - Update the minimum unfairness found.

// # Steps:
// # 1. Base case: If all cookies are assigned, calculate unfairness and update the result.
// # 2. Assign the current cookie to every child one by one.
// # 3. Recursively assign the next cookie.
// # 4. Backtrack by removing the assigned cookie and trying the next possibility.

// # Time Complexity: O(k^n) (Each cookie has k choices)
// # Space Complexity: O(k) (Array to track cookie distribution)

    