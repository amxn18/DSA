#include <bits/stdc++.h>
using namespace std;

// TC : O(n) SC: O(n)
class Solution {
  public:
    int t[100001][4];
    int solve(int day, int lastTask, vector<vector<int>>& mat){
        if(day == 0){
            int maxi = 0;
            for(int task = 0; task < 3; task++){
                if(task != lastTask){
                    maxi = max(maxi, mat[0][task]);
                }
            }
            return maxi;
        }
        if(t[day][lastTask] != -1) return t[day][lastTask];
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != lastTask){
                int points = mat[day][task] + solve(day-1, task, mat);
                maxi = max(maxi, points);
            }
        }
        return t[day][lastTask] = maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        memset(t, -1, sizeof(t));
        return solve(n-1, 3, mat);
    }
};