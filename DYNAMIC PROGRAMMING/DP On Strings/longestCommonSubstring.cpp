#include <bits/stdc++.h>
using namespace std;

// LC 718 - Longest Common Substring
// Method 1: Memoization TC = O(m*n) SC = O(m*n) + O(m+n)
class Solution {
public:
    int m, n;
    int maxi = 0;
    int t[1001][1001];
    int solve(vector<int>& nums1, vector<int>& nums2, int i , int j){
        if(i >= m || j >= n) return 0;
        if(t[i][j] != -1) return t[i][j];

        if(nums1[i] == nums2[j]){
            t[i][j] = 1 + solve(nums1, nums2, i+1, j+1);
            maxi = max(maxi, t[i][j]);
        }
        else t[i][j] = 0;
        return t[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        memset(t, -1, sizeof(t));
        maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                solve(nums1, nums2, i, j);
            }
        }
        return maxi;
    }
};
// Method 2: Tabulation TC = O(m*n) SC = O(m*n)

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int maxi = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};