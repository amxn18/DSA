#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void f(int start, int k, int target, vector<int>& temp){
        if(k==0){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        for(int i=start; i<=9; i++){
            if(i > target) break;
            temp.push_back(i);
            f(i+1, k-1, target-i, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        f(1, k, n, temp);
        return result;   
    }
};

// LC 216. Combination Sum III
// TC --> O(9Ck * k) SC --> O(k) + O(9Ck * k)
// where 9Ck is the number of combinations of choosing k numbers from 1 to 9
// and k is the average length of each combination