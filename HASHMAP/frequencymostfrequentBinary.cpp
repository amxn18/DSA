#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bSearch(int targetIdx, vector<int>& nums, int k, vector<long>& prefixSum) {
        int target = nums[targetIdx];
        int l = 0;
        int r = targetIdx;
        int x = targetIdx;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long cnt = targetIdx - mid + 1;
            long sum = target * cnt;
            long oriSum = prefixSum[targetIdx] - (mid > 0 ? prefixSum[mid - 1] : 0);
            long ops = sum - oriSum;

            if (ops > k) {
                l = mid + 1;
            } else {
                x = mid;
                r = mid - 1;
            }
        }

        return targetIdx - x + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int freq = bSearch(i, nums, k, prefixSum);
            result = max(result, freq);
        }

        return result;
    }
};


// # LeetCode 1838 - Frequency of the Most Frequent Element

// ## Problem Statement:
// Given an array `nums` and an integer `k`, you can increment any element by 1 at most `k` times.
// Return the maximum possible frequency of the most frequent element after at most `k` operations.

// ---

// ## Approach: Binary Search + Prefix Sum

// 1. Sort the array to ensure the target value is always to the right of the values we may increase.
// 2. Build a prefix sum array for quick range sum queries.
// 3. For each index `i` (treated as the target value), use binary search to find the **leftmost index** from which all elements can be increased to match `nums[i]` using at most `k` operations.
// 4. For a given window `[mid, i]`, calculate the cost to make all values equal to `nums[i]`:
//    - Total required value = `nums[i] * count`
//    - Current value in range = prefix sum
//    - Operations needed = (required) - (current)
// 5. If the cost is within `k`, update the max frequency.
// 6. Track and return the maximum frequency obtained.

// ---

// ## Example:
// nums = [1,2,4], k = 5

// Sorted: [1,2,4]

// Trying to make multiple elements equal to 4:
// - 1 → 4 (3 ops), 2 → 4 (2 ops) → Total = 5 ops → max freq = 3

// ---

// ## Time Complexity:
// - Sorting: O(n log n)
// - Prefix sum: O(n)
// - For each index: O(log n) binary search
// => Overall: O(n log n)

// ---

// ## Space Complexity:
// - O(n) for prefix sum array

// ---



