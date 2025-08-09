#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long reqHrs(vector<int>& piles, int hourly) {
        int n = piles.size();
        long long totalHrs = 0; // long long to avoid overflow
        for (int i = 0; i < n; i++) {
            totalHrs += ((long long)piles[i] + hourly - 1) / hourly; 
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhrs = reqHrs(piles, mid);

            if (totalhrs <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// LC 875
// TC: O(n log m) where n is the number of piles and m is the maximum pile size
// SC: O(1) since we are using constant space