#include <bits/stdc++.h>
using namespace std;

// LC 120
// Method 1: Recursion + Memoization TC = O(n*n) and SC = O(n*n) + O(n) -> TLE
class Solution {
public:
    int n;
    int t[201][201];
    int solve(vector<vector<int>>& triangle, int i, int j){
        if(i == n-1) return t[i][j] = triangle[i][j];
        if(t[i][j] != -1) return t[i][j];
        int down = solve(triangle, i+1, j);
        int diagnol = solve(triangle, i+1, j+1);

        return t[i][j] = triangle[i][j] + min(down, diagnol);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t, -1, sizeof(t));
        return solve(triangle, 0, 0);
    }
};

// Method 2: Bottom-Up DP TC = O(n*n) and SC = O(n*n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[i][j] = dp[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Method 3: Space Optimized DP TC = O(n*n) and SC = O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};