#include <bits/stdc++.h>
using namespace std;

// LC 53: Maximum Subarray (Kadane's Algorithm)
// Method 1 Brute Force: O(n^2) SC O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// Method 2: Using Prefix Sum: O(n) SC O(n) : At every idx which previous prefix should we remove to maximise my current sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int minPrefix = 0;
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            prefix += nums[i];
            int sum = prefix - minPrefix;
            maxSum = max(maxSum, sum);
            minPrefix = min(prefix, minPrefix);
        }
        return maxSum;
    }
};