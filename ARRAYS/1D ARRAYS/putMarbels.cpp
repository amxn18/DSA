#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            int m = n - 1;
    
            // Create a list to store the sum of every adjacent pair
            vector<int> pairsum(m, 0);
            for (int i = 0; i < m; i++) {
                pairsum[i] = weights[i] + weights[i + 1];
            }
    
            // Sort the pairsum to find the smallest and largest k-1 cuts
            sort(pairsum.begin(), pairsum.end());
    
            long long maxSum = 0;
            long long minSum = 0;
    
            // Sum of the smallest k-1 pair sums (minimum configuration)
            // and the largest k-1 pair sums (maximum configuration)
            for (int i = 0; i < k - 1; i++) {
                minSum += pairsum[i];
                maxSum += pairsum[m - 1 - i];
            }
    
            // The result is the difference between max and min configurations
            return maxSum - minSum;
        }
    };
    

// # 🧮 LeetCode 2551 – Put Marbles in Bags

// ## 📘 Problem Explanation:
// You're given an array `weights` representing the weights of marbles in a row. You need to divide them into exactly `k` contiguous groups. The score of a division is the sum of the first and last marble in each group. Your task is to **maximize the difference** between the maximum and minimum possible scores you can get from any such valid `k` divisions.

// ## 🧠 Approach:
// - To divide into `k` groups, you need to make `k-1` cuts between adjacent elements.
// - Each cut contributes a cost of `(weights[i] + weights[i+1])` to the total score.
// - So, generate all `n-1` adjacent pair sums.
// - Sort this list:
//   - Take the **smallest (k-1)** pair sums for the **minimum** score.
//   - Take the **largest (k-1)** pair sums for the **maximum** score.
// - Return the difference `maxSum - minSum`.

// ## ⏱️ Time Complexity:
// - `O(n log n)` due to sorting of pair sums.

// ## 🧠 Space Complexity:
// - `O(n)` for storing pair sums.

// ## ✅ Final Answer:
// - Return the difference between maximum and minimum possible scores.
