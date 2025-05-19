#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int result = INT_MIN; // Stores the maximum number of valid transfer requests
        int m; // Number of requests
    
        void solve(int idx, int count, int n, vector<int>& resultant, vector<vector<int>>& requests){
            if(idx >= m){ // Base condition: If all requests have been considered
                bool allZero = true; 
                for(int &x : resultant){
                    if(x != 0) { // If any building has an imbalance, the solution is invalid
                        allZero = false;
                        break;
                    }
                }
                if(allZero) { 
                    result = max(result, count); // Update the result if all buildings are balanced
                }
                return;
            }
            
            int from = requests[idx][0]; // The building from which an employee is moved
            int to = requests[idx][1];   // The building to which an employee is moved
            
            // **Choose to Accept the Request**
            resultant[from]--; // Reduce one employee from "from" building
            resultant[to]++;   // Add one employee to "to" building
            solve(idx+1, count+1, n, resultant, requests);
            
            // **Backtrack: Undo the Request**
            resultant[from]++;
            resultant[to]--;
            solve(idx+1, count, n, resultant, requests); // Move to the next request without accepting
        }
    
        int maximumRequests(int n, vector<vector<int>>& requests) {
            m = requests.size();
            vector<int> resultant(n, 0); // Should be size `n`, not `m`, to track net change per building
            solve(0, 0, n, resultant, requests);
            return result;
        }
    };
//     # Problem: Maximum Number of Achievable Transfer Requests (Leetcode 1601)
// # Approach: Backtracking

// # 1. We have `n` buildings and `m` transfer requests (move employee from building A to B).
// # 2. Goal: Select maximum number of requests such that at the end, all buildings have net zero change.

// # Steps:
// # - Use backtracking to explore all subsets of requests.
// # - Maintain a `resultant` array of size `n` to track net change in each building.
// # - At each step:
// #   - Accept the request (update `resultant` and recurse).
// #   - Backtrack (undo the change) and try ignoring the request.
// # - If at the end `resultant` has all zeros, update the `result` (max requests accepted).

// # Time Complexity: O(2^m) - Every request has two choices (accept/reject)
// # Space Complexity: O(n) - Storing the net change of employees per building
