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

// Method 3: Kadane's Algorithm: O(n) SC O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};

// Printing the subarray with maximum sum: O(n) SC O(1)
class Solution {
public:

    vector<int> maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        int start = 0;
        int end = 0;
        int tempStart = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if(currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
            // Discard the current sum if it becomes negative, and start a new subarray from the next index
            if(currentSum < 0) {
                currentSum = 0;
                tempStart = i + 1;
            }
        }
        vector<int> ans;
        for(int i = start; i <= end; i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};