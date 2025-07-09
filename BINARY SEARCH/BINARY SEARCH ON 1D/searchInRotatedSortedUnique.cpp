#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            // Identify Sorted Half
            //Left sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                } else low = mid+1;
            }
            else {
                if(nums[mid] <= target && target<=nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};

// LeetCode 33: Search in Rotated Sorted Array
// TC --> O(log n)
// SC --> O(1)