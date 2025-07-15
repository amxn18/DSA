#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int isPossible(vector<int>& stalls, int dist, int k){
        int n = stalls.size();
        int cnt = 1;
        int lastCow = stalls[0];
        for(int i=1; i<n; i++){
            if(stalls[i] - lastCow >= dist){
                cnt++;
                lastCow = stalls[i];
            }
            if(cnt >= k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        sort(stalls.begin(), stalls.end());
        while(low <= high){
            int mid = low + (high -low)/2;
            if(isPossible(stalls, mid, k) == true){
                low = mid+1;
            } else high = mid-1;
        }
        return high;
        
    }
};


// Tc : O(n log m) m --> maximum distance between first and last stall
// Sc : O(1)