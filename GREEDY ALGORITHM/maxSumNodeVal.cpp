#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        typedef long long ll;
        long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            ll sum = 0;
            int count = 0; // Count of numbers where (num ^ k) > num
            int minLoss = INT_MAX; // Stores the minimum loss when choosing (num ^ k)
            
            for(ll num : nums){
                if((num^k) > num){ // If flipping num with k increases value
                    count++; // Increase count of flipped numbers
                    sum += (num^k); // Add the flipped value to sum
                } else sum += num; // Otherwise, add num as it is
                
                minLoss = min((long long)minLoss, abs(num - (num^k))); // Track minimum loss
            }
            
            if(count % 2 == 0){
                return sum; // If even number of flips, return sum directly
            } else return sum - minLoss; // If odd, subtract minLoss to make count even
        }
    };

//     # Problem: LC 3068 - Maximum Value Sum
// # 
// # Approach:
// # 1. Iterate through the array and compute the sum by replacing numbers with (num ^ k) 
// #    if it increases the value.
// # 2. Track:
// #    - count → Number of times we replaced num with (num ^ k).
// #    - minLoss → Minimum absolute loss when switching between num and (num ^ k).
// # 3. If count is even, return the computed sum.
// # 4. If count is odd, subtract minLoss to balance the flips and get the maximum valid sum.
