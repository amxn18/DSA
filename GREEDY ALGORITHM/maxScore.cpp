#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            int i = k;
            int j = k;
            int currMin = nums[k];
            int result = nums[k];
            while(i>0 || j < (n-1)){
                int leftVal = i>0 ? nums[i-1] : 0;
                int rightVal = j < (n-1) ? nums[j+1] : 0;
                if(leftVal > rightVal){
                    i--;
                    currMin = min(currMin, nums[i]);
                } else {
                    j++;
                    currMin = min(currMin, nums[j]);
                }
                result = max(result, currMin*(j-i+1));
            } 
            return result;
        }
    };

    // Leetcode 1793: Maximum Score of a Good Subarray
// Approach: Two Pointers + Greedy
// - Start from index k and expand outwards using two pointers (i, j).
// - Maintain the minimum value in the current subarray (`currMin`).
// - Expand towards the side with the larger value to maximize the score.
// - Update the maximum score (`result`) at each step as `currMin * (j - i + 1)`.
// - Continue until reaching the array bounds.
// Time Complexity: O(N) | Space Complexity: O(1)