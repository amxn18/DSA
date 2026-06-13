#include <bits/stdc++.h>
using namespace std;

// LC 410. Split Array Largest Sum
// TC: O(n log m) where m is the sum of elements in nums
class Solution {
public:
    int findSplits(vector<int>& arr, int s){
        int splits = 1;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            if(sum + arr[i] <= s) sum += arr[i];
            else{
                splits++;
                sum = arr[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int splits = findSplits(nums, mid);
            if(splits > k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
