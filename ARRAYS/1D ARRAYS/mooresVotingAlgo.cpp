#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el;
        int ctr = 0;
        for(int i=0; i<n; i++){
            if(ctr == 0){
                ctr=1;
                el = nums[i];
            }
            else if(nums[i] == el) ctr++;
            else ctr --;
        }   
// If Problem Mentions there will always be a majority element then verify otherwise not
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el) count++;
        }
        if(count > n/2) return el;
        return -1;
    }
};

// LC --> 169
// TC --> O(n) if no verify
// TC --> O(2n) if verify
// SC --> O(1)