#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int result;  // Stores the count of beautiful subsets
        int K;  // Difference value given in the problem
    
        // Backtracking function to generate subsets
        void solve(int idx, vector<int>& nums, unordered_map<int, int>& mp){
            // Base case: If we reach the end of nums, count the valid subset
            if(idx >= nums.size()){
                result++;  // Increment the count of valid subsets
                return;
            }
    
            // Option 1: Do not take the current element
            solve(idx+1, nums, mp);
    
            // Option 2: Take the current element only if it does not violate the condition
            if(!mp[nums[idx] - K] && !mp[nums[idx] + K]){  
                mp[nums[idx]]++;  // Mark this number as used
                solve(idx+1, nums, mp);  // Recur for the next index
                mp[nums[idx]]--;  // Backtrack (undo the choice)
            }
        }
    
        // Main function to find the number of beautiful subsets
        int beautifulSubsets(vector<int>& nums, int k) {
            result = 0;  // Initialize the result count
            K = k;  // Store the given difference value
            unordered_map<int, int> mp;  // Map to track elements in subset
            solve(0, nums, mp);  // Start backtracking
            return result - 1;  // Exclude the empty subset from the count
        }
    };
    
   
