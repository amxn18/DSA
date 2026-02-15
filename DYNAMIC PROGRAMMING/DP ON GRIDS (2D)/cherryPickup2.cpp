#include <bits/stdc++.h>
using namespace std;

// LC 1463. Cherry Pickup II 
// Recursion + Memoization TC = O(m*n*n*9) SC = O(m*n*n) + O(m) for recursion stack
class Solution {
public:
    int m, n;
    int t[71][71][71];
    int solve(vector<vector<int>>& grid, int i, int j1, int j2){
        if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
        if(i == m-1){ // Last Row
            if(j1 == j2) return grid[i][j1];  // Same cell
            else return grid[i][j1] + grid[i][j2];
        }
        if(t[i][j1][j2] != -1) return t[i][j1][j2];
        int maxcherries = 0;
        for(int dir1 = -1; dir1 <= 1; dir1++){
            for(int dir2 = -1; dir2 <= 1; dir2++){
                int next = solve(grid, i+1, j1+dir1, j2+dir2);
                int cherries = 0;
                if(j1 == j2) cherries = grid[i][j1];
                else cherries = grid[i][j1] + grid[i][j2];
                maxcherries = max(maxcherries, cherries + next);
            }
        }
        return t[i][j1][j2] = maxcherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, n-1);
    }
};


// Tabulation TC = O(m*n*n*9) SC = O(m*n*n)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        // Last row
        for(int j1= 0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i=m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxCherries = 0;
                    for(int d1 = -1; d1 <= 1; d1++){
                        for(int d2 = -1; d2 <= 1; d2++){
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;
                            if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n) maxCherries = max(maxCherries, dp[i+1][nj1][nj2]);
                        }
                    }
                    int cherries = 0;
                    if(j1 == j2) cherries = grid[i][j1];
                    else cherries = grid[i][j1] + grid[i][j2];
                    dp[i][j1][j2] = cherries + maxCherries;
                }
            }
        }
        return dp[0][0][n-1];
    }
};