#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int n = bloomDay.size();
        int boquets = 0;
        int ctr = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                ctr++;
            } else{
                boquets += ctr/k;
                ctr = 0;
            }
        }
        boquets += ctr/k;
        return boquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = (m * 1LL) * (k*1LL);
        if(val>n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// LC 1482
// TC: O(n log m) 
// SC: O(1) 