#include <bits/stdc++.h>
using namespace std;

// LC 2653. Sliding Subarray Beauty
// TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        vector<int> freq(51, 0);
        int i=0; 
        int j = 0;
        while(j < n){
            if(nums[j] < 0) freq[-nums[j]]++;
            if(j-i+1 == k){
                int count = 0;
                int beauty = 0;
                for(int i=50; i>=1; i--){
                    count += freq[i];
                    if(count >= x){
                        beauty = -i;
                        break;
                    }
                }
                result.push_back(beauty);
                if(nums[i] < 0) freq[-nums[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};