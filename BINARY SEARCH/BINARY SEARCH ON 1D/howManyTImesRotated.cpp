#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[high]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    idx = low;
                }
                break;
            }
            if (arr[low] <= arr[mid]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    idx = low;
                }
                low = mid + 1;
            }
            else {
                if (arr[mid] < ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid -1;
            }
        }

        return idx;
    }
};


