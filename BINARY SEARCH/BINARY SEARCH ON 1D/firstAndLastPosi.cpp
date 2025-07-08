#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool firstFind){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                result = mid;
                if(firstFind == true){
                    high = mid-1; // Search on left side
                } else low = mid+1; // Search on right side
            } 
            else if(target > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};

// LeetCode 34: Find First and Last Position of Element in Sorted Array
// TC --> O(log n)
// SC --> O(1)