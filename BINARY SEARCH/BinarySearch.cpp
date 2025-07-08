#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};

// LeetCode 704: Binary Search
// TC --> O(log n)
// SC --> O(1) 





// Recursive version
class Solution {
public:
    int BinarySearch(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return BinarySearch(nums, mid+1, high, target);
        else return BinarySearch(nums, low, mid-1, target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        return BinarySearch(nums, low, high, target);
    }
};