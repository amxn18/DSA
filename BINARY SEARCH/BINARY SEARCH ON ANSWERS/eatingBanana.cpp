#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalHours = 0;

            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid;  // Ceil division without using floating point
            }

            if (totalHours <= h) {
                result = mid;          // Try smaller k
                right = mid - 1;
            } else {
                left = mid + 1;        // Try larger k
            }
        }
        return result;
    }
};

// LC 875
// TC: O(n log m) where n is the number of piles and m is the maximum pile size
// SC: O(1) since we are using constant space