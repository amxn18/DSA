#include <bits/stdc++.h>
using namespace std;

vector<int> leaderElements(vector<int>& nums){
    int n = nums.size();
    vector<int> result;
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i++){
        if(nums[i] > maxi) result.push_back(nums[i]);
        maxi = max(maxi, nums[i]);
    }
    
    // If mentioned in the problem statement to return in descending order
    sort(result.begin(), result.end(), greater<int>());
    return result;
}

// Leader Elements in an Array
// TC --> O(n + nlogn) --> O(nlogn) if sorting is required
// TC --> O(n) if sorting is not required
// SC --> O(n)

