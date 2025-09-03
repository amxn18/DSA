#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void find(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds){
            if(target == 0){
                ans.push_back(ds);
                return;
            }

            for(int i = ind; i<arr.size(); i++){
                if(i> ind && arr[i] == arr[i-1]) continue;
                if(arr[i]> target){
                    break;
                }
                ds.push_back(arr[i]);
                find(i+1, target-arr[i],  arr, ans , ds);
                ds.pop_back();
            }
        }
    

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        find(0, target, candidates, ans, ds);
        return ans;
    }
};

// LC 40
// TC -> O(2^n * k) , SC -> O(k*x) + O(k)  (k = avg length of each combination, x = no of combinations)
// SC -> O(k) for the recursion stack space