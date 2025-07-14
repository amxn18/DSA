#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(vector<int>& weights, int cap){
        int n = weights.size();
        int days = 1;
        int load = 0;
        for(int i=0; i<n; i++){
            if(load + weights[i] > cap){
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int daysreq = countDays(weights, mid);
            if(daysreq <= days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

// LC 1011
// TC: O(n log m) m --> sum of all weights
// SC: O(1)