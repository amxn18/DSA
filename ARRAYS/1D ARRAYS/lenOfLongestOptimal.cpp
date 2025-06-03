#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>&nums, int k){
    int n = nums.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    long long sum = 0;
    while(r < n){
        while(l<=r && sum > k){
            sum -= nums[l];
            l++;
        }
        if(sum == k) maxLen = max(maxLen, r-l+1);
        r++;
        if(r<n) sum += nums[r];
    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << "Length of longest subarray with sum " << k << ": " << longestSubarray(nums, k) << endl;
    return 0;
}

// TC --> O(2n) --> O(n)
// SC --> O(1)