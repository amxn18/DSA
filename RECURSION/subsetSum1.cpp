#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void f(int idx, int sum, vector<int>& arr, vector<int>& sumArray){
        int n = arr.size();
        if(idx == n){
            sumArray.push_back(sum);
            return;
        }
        f(idx+1, sum+arr[idx], arr, sumArray);
        f(idx+1, sum, arr, sumArray);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sumArray;
        f(0, 0, arr, sumArray);
        return sumArray;
    }
};

// TC -> O(2^N)
// SC -> O(2^N) + O(N)