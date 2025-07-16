#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to count how many subarrays are formed if max subarray sum is <= mid
    int solve(vector<int>& nums, int mid) {
        int count = 1; // At least one subarray
        int sum = 0;
        for (int num : nums) {
            if (sum + num <= mid) {
                sum += num;
            } else {
                count++;
                sum = num;
            }
        }
        return count;
    }

    int findMaxSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1; // If splits > elements, invalid

        int low = *max_element(nums.begin(), nums.end()); // Minimum max subarray sum possible
        int high = accumulate(nums.begin(), nums.end(), 0); // Maximum max subarray sum possible

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int splits = solve(nums, mid);
            if (splits > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findMaxSubarray(nums, k);
    }
};


// Same As Book Allocation Problem
// TC: O(n log m) where m is the sum of elements in nums
// SC: O(1)
// LC 410