#include <bits/stdc++.h>
using namespace std;

// Aggressive Cows
// TC: O(NlogN) + O(logN * N) = O(NlogN)
class Solution {
  public:
    bool isPossible(vector<int>& nums, int dist, int k){
        int countCows = 1;
        int lastCow = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - lastCow >= dist){
                countCows++;
                lastCow = nums[i];
            } 
            if(countCows >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int ans = -1;
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(stalls, mid, k)){
                ans = mid;
                low = mid+1; // need max 
            }
            else high = mid-1;
        }
        return ans;
    }
};