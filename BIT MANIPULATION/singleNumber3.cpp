#include <bits/stdc++.h>
using namespace std;

// LC 260. Single Number III
// Method 1: Using HashMap
// TC O(n), SC O(n)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        vector<int> result;
        for(auto it : freq){
            if(it.second == 1) result.push_back(it.first); 
        }
        return result;
    }
};

// Method 2: Using Bit Manipulation
// TC O(n), SC O(1)