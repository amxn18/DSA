#include <bits/stdc++.h>
using namespace std;

// Memoization TC O(N*target) SC O(N*target) + O(N) for recursion stack
class Solution {
  public:
    int t[51][1001];
    int solve(vector<int>& arr, int idx, int target){
        if(idx == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
}
        
        if(t[idx][target] != -1) return t[idx][target];
        int notTake = solve(arr, idx-1, target);
        int take = false;
        if(target >= arr[idx]) take = solve(arr, idx-1, target - arr[idx]);
        
        return t[idx][target] = take + notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if((totalSum - diff < 0) || ((totalSum - diff) % 2 != 0)) return false;
        int target = (totalSum - diff)/ 2;
        return solve(arr, n-1, target);
    }
};


// Tabulation TC O(N*target) SC O(N*target)
class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {

        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if(totalSum < diff) return 0;
        if((totalSum + diff) % 2 != 0) return 0;

        int target = (totalSum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){

                int notTake = dp[i-1][t];

                int take = 0;
                if(arr[i] <= t)
                    take = dp[i-1][t - arr[i]];

                dp[i][t] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};