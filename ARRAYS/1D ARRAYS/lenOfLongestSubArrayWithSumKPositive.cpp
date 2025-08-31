#include <bits/stdc++.h>
using namespace std;

// Better approach using Hashing and optimal approach for both positive and negative numbers
// TC = O(n)
// SC = O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long, long> mp;
        long long sum = 0;
        int len = 0;
        for(int i =0; i<n; i++){
            sum += arr[i];
            if(sum == k) len = max(len, i+1);
            long long rem = sum - k;
            if(mp.find(rem) !=mp.end()){
                int length = i - mp[rem];
                len = max(len, length);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return len;
    }
};


int longestSubarray(vector<int>&nums, int k){
    int n = nums.size();
    map<long, long> mp;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i; // Store the first occurrence of the sum
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << "Length of longest subarray with sum " << k << ": " << longestSubarray(nums, k) << endl;
    return 0;
}