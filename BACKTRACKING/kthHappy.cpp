#include <bits/stdc++.h>
using namespace std; 
class Solution {
    public: 
        // Recursive function to generate happy strings
        void solve(int n, string& curr, int& count, int& k, string& result){
            // Base case: if the current string reaches the required length
            if(curr.length() == n){
                count++; // Increment count of happy strings generated
                if(count == k){ // If the k-th happy string is found
                    result = curr; // Store the result
                }
                return;
            }
    
            // Loop through characters 'a', 'b', 'c'
            for(char ch = 'a'; ch <= 'c'; ch++){
                if(!curr.empty() && curr.back() == ch) continue; // Ensure no two adjacent characters are the same
                curr.push_back(ch); // Add character to the current string
                solve(n, curr, count, k, result); // Recursive call for the next position
                curr.pop_back(); // Backtrack by removing the last character
            }
        }
    
        // Function to find the k-th lexicographically smallest happy string
        string getHappyString(int n, int k) {
            string curr = ""; // Temporary string to build happy strings
            string result = ""; // Store the k-th happy string
            int count = 0; // Counter to track the number of happy strings generated
            solve(n, curr, count, k, result); // Start backtracking from an empty string
            return result; // Return the k-th happy string (or empty if not found)
        }
    };
    // # This program generates happy strings of length `n` using backtracking. LC-1415
    // # A happy string is a string where:
    // # - Only characters 'a', 'b', and 'c' are used.
    // # - No two adjacent characters are the same.
    // #
    // # The function `solve` generates happy strings one by one and keeps track of the count.
    // # Once the k-th happy string is found, it is stored in `result` and returned.
    // #
    // # Key points:
    // # - `curr`: Stores the current string being built.
    // # - `count`: Keeps track of how many happy strings are generated.
    // # - `k`: Specifies which happy string should be returned.
    // # - The function backtracks to explore all possibilities.
    // #
    // # Time Complexity: O(3^n) (since each position has 3 choices).
    // # Space Complexity: O(n) (for recursive calls and storing the current string).
        