#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]){   // LHS Sorted
                if(nums[low] <= target && target <= nums[mid]) high = mid-1; // Target is on LHS
                else low = mid+1; // LHS Sorted but Target is on RHS
            }
            else{
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                high = mid-1;
            }
        }
        return false;
    }
};

// LC 81
// TC --> O(log n)
// SC --> O(1)