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