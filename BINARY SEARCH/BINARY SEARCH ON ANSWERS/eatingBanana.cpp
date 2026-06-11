#include <bits/stdc++.h>
using namespace std;

// LC 875. Koko Eating Bananas
// TC = O(nlogm) where n is the number of piles and m is the maximum pile size

class Solution {
public:
    long long calculateTime(vector<int>& piles, int hourly){
        long long total = 0;
        for(int i=0; i<piles.size(); i++){
            total += ceil((double)piles[i]/hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            long long hours = calculateTime(piles, mid);
            if(hours <= h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};