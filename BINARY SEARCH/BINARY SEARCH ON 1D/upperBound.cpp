#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& nums, int target){
    int n = nums.size();
    int idx = n;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] > target){
            idx = mid;
            high = mid - 1; // Move left to find the first occurrence
        } else low = mid+1;
    }
    return idx;
}

// TC --> O(log n)
// SC --> O(1)