#include <bits/stdc++.h>
using namespace std;

// LC 152: Maximum Product Subarray
// Method 1: Brute Force: O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxProd = LONG_MIN;
        for(int i=0; i<n; i++){
            long long prod = 1;
            for(int j=i; j<n; j++){
                prod = prod*nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return (int)(maxProd);
    }
};

// Method 2: Kadane's Algorithm: O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for(int i=1; i<n; i++){
            int num = nums[i];
            int tempMax = max({num, currMax*num, currMin*num});
            int tempMin = min({num, currMax*num, currMin*num});

            currMax = tempMax;
            currMin = tempMin;

            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};