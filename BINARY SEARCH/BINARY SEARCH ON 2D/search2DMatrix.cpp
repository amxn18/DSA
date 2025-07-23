#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool BS(vector<int>& matrix, int target){
        int low = 0;
        int high = matrix.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid] == target) return true;
            else if(target > matrix[mid]) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]) return BS(matrix[i], target);
        }
        return false;
    }
};
// LC: 74
// TC : O(n + log(m))
// SC : O(1)



// LC: 240
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m-1;  // last column
        while(i<n &&  j>=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};

// TC : O(n + m)
// SC : O(1)