#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfAll(vector<int>& nums, int divisor){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ceil(double(nums[i])/double(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = -1;
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(sumOfAll(nums, mid) <= threshold){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// LC 1283
// TC: O(n log m) m --> maximum element in nums
// SC: O(1)