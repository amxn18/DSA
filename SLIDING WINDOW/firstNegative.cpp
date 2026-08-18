#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        queue<int> q;
        int i = 0; 
        int j = 0;
        while(j<n){
            if(nums[j] < 0) q.push(nums[j]);
            if(j-i+1 == k){
                if(!q.empty()) result.push_back(q.front());
                else result.push_back(0);
                
                if(nums[i] < 0 && !q.empty()) q.pop();
                i++;
            }
            j++;
        }
        return result;
    }
};