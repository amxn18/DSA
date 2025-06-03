#include <bits/stdc++.h>
using namespace std;

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
        mp[sum] = i;
    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    cout << "Length of longest subarray with sum " << k << ": " << longestSubarray(nums, k) << endl;
    return 0;
}