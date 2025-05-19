#include <bits/stdc++.h>
using namespace std;

// LC 2366 TC--> O(n)
class Solution {
    public:
        long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long minOp = 0;
        for(int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            long long parts = (long long)nums[i] / nums[i + 1];
            if ((long long)nums[i] % nums[i + 1] != 0) parts++;
            minOp += (parts - 1);
            nums[i] = nums[i] / parts;
        }
        return minOp;
        }
    };