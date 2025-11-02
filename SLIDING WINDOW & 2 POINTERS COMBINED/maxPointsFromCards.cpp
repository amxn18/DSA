#include <bits/stdc++.h>
using namespace std;

// LC 1423
// TC O(2k) SC O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0;
        int rSum = 0;
        int maxSum = 0;
        for(int i=0; i<k; i++){
            lSum += cardPoints[i];
        }
        maxSum = lSum;
        int rIdx = n-1;
        for(int i = k-1; i >=0; i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[rIdx];
            rIdx--;
            maxSum = max(maxSum, (lSum+rSum));
        }
        return maxSum;
    }
};