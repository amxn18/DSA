#include <bits/stdc++.h>
using namespace std;
class Solution {
    public: 
        void solve(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
            if (idx >= nums.size()) {
                if (temp.size() > result.size()) {
                    result = temp; // Store the largest subset found so far
                }
                return;
            }
            // Take current element if divisible by previous element
            if (prev == -1 || nums[idx] % prev == 0) {
                temp.push_back(nums[idx]);
                solve(idx + 1, nums, result, temp, nums[idx]);
                temp.pop_back(); // Backtrack
            } 
            // Skip current element
            solve(idx + 1, nums, result, temp, prev);
        }
        
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(begin(nums), end(nums)); // Sorting to ensure divisibility
            vector<int> result, temp;
            solve(0, nums, result, temp, -1);
            return result;
        }
    };
    