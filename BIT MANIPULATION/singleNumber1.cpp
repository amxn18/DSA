#include <bits/stdc++.h>
using namespace std;

// LC 136. Single Number
// Method: Using Bit Manipulation
// TC O(n), SC O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(int i=0; i<nums.size(); i++){
            XOR = XOR^nums[i];
        }
        return XOR;
    }
};