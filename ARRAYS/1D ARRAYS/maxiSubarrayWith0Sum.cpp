#include <bits/stdc++.h>
using namespace std;
int maxiSubArray(vector<int>& nums){
    unordered_map<int,int> mp;
    int n = nums.size();
    int maxi = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == 0){
            maxi = i+1;
        }
        else {
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i-mp[sum]);
            }
            else mp[sum] = i;
        }
    }
    return maxi;
}
int main(){
    vector<int> nums = {1, -1, 2, -2, 3, -3};
    cout << "Length of the longest subarray with sum 0: " << maxiSubArray(nums) << endl;
    return 0;
}


// TC --> O(n)