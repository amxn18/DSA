#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countOneFirstOcc(vector<int> &arr, int m, int k){
        int low = 0;
        int high = m-1;
        int ans = m;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int cntMax = 0;
        int idx = -1;
        for(int i=0; i<n; i++){
            int cnt = m - countOneFirstOcc(arr[i], m, 1);
            if(cnt > cntMax){
                cntMax = cnt;
                idx = i;
            }
        }
        return idx;
    }
};

// TC : O(n * log(m))
// SC : O(1)

// Found The Index of First Occurrence of 1 in Each Row then Count the Number of 1s in Each Row
// and Return the Index of Row with Maximum 1s