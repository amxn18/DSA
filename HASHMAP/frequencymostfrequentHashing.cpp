#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        sort(nums.begin(), nums.end());

        int maxFreq = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int target = nums[i];
            long long operations = k;
            int count = 1;

            for (int j = i - 1; j >= 0; --j) {
                int diff = target - nums[j];
                if (operations >= diff) {
                    operations -= diff;
                    count++;
                } else {
                    break;
                }
            }

            maxFreq = max(maxFreq, count);
        }

        return maxFreq;
    }
};

// #  LeetCode 1838 - Frequency of the Most Frequent Element

// ##  Problem Statement:
// You are given an array `nums` and an integer `k`. You can increment any element by 1, at most `k` times in total.
// Your goal is to maximize the **frequency of any number** after performing these operations.

// ---

// ##  Approach (Brute Force + Hashing):

// 1. Count frequency of all elements using a hashmap (unordered_map).
// 2. Sort the array in ascending order.
// 3. Iterate from the largest number to smallest:
//    - Set this number as the "target" value.
//    - Try to increase smaller numbers up to match this target using at most `k` operations.
//    - Count how many elements can be made equal to this target.
// 4. Track the maximum frequency found.

// Hashing helps us count occurrences, though it’s not fully utilized in this version.

// ---

// ##  Example:
// nums = [1,2,4], k = 5  
// Make all elements = 4:
// - 1 → 2 → 3 → 4 (3 operations)
// - 2 → 3 → 4 (2 operations)
// → Total cost = 5
// Frequency of 4 = 3

// ---

// ## ⏱ Time Complexity:
// - Sorting: O(n log n)
// - Nested loop (worst case): O(n^2)
// ➡️ **Overall: O(n^2)** in worst case (can lead to TLE on large inputs)

// ---

// ##  Space Complexity:
// - O(n) for the hashmap used to count frequencies.

// ---

// ##  Note:
// This is a brute-force method for learning purposes.
// The **optimal** way is to use **sliding window + sorting** for O(n log n) solution.


