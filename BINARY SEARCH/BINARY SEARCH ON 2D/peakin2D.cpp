#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int findRow(vector<vector<int>> &mat, int mid, int n, int m){
    int maxi = -1;
    int idx = -1;
    for(int i=0; i<n; i++){
        if(mat[i][mid] > maxi){
            maxi = mat[i][mid];
            idx = i;
        }
    }
    return idx;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = findRow(mat, mid, n, m);
            int left = mid-1 >=0 ? mat[row][mid-1] : -1;
            int right = mid+1 < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < left) high = mid-1;  // Peak Possible on Left side
            else low = mid+1; // Peak Possible On Right Side
        }
        return {-1, -1};
    }
};

// TC : O(n * log(m))
// SC : O(1)
// LC : 162