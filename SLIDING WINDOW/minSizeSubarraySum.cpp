#include <bits/stdc++.h>
using namespace std;

// LC 209. Minimum Size Subarray Sum
// TC: O(n) SC: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int minLen = INT_MAX;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                minLen = min(minLen, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};