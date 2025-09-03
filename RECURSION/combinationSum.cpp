#include <bits/stdc++.h>
using namespace std;

// LC 39
// TC --> O(2^t * k)  (t -> target, k -> average length of each combination)
// SC --> O(k*x) 
class Solution {
public:
    vector<vector<int>> result;
    void find(int idx, int target, vector<int>& candidates, vector<int>& temp){
        int n = candidates.size();
        if(idx == n){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            find(idx, target-candidates[idx], candidates, temp);
            temp.pop_back();
        }
        find(idx+1, target, candidates, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        find(0, target, candidates, temp);
        return result;
    }
};