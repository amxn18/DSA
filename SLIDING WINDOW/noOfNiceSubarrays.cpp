#include <bits/stdc++.h>
using namespace std;

// LC 1248
// TC : O(2N)*2
// SC : O(1)
class Solution {
public:
    int atmost(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int oddCount = 0;
        int count = 0;
        
        int i = 0;
        int j = 0;
        while(j<n){
            if(nums[j]%2 != 0) oddCount++;
            while(oddCount > k){
                if(nums[i] % 2 != 0) oddCount--;
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};
